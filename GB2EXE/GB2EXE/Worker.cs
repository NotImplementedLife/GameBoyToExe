using GB2EXE.Properties;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GB2EXE
{
    internal static class Worker
    {
        public static void DecompressGBP(string path)
        {
            Stream data = new MemoryStream(Resources.gbp);            

            ZipArchive archive = new ZipArchive(data);            
            foreach (ZipArchiveEntry entry in archive.Entries)
            {                                
                Debug.WriteLine(entry.FullName);
                if(entry.FullName.EndsWith("/"))
                    continue;
                Stream entryStream = entry.Open();
                var dest = Path.Combine(path, entry.FullName);

                if(!Directory.Exists(Path.GetDirectoryName(dest)))
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(dest));
                }

                using (var fileStream = File.Create(dest)) 
                {                    
                    entryStream.CopyTo(fileStream);
                }                                
            }
        }

        static readonly int OffsetGB = 0x34C10;
        static readonly int OffsetLen = 0x34C00;

        public static void EditGBPExecutable(string path, string title, byte[] gbRom)
        {
            byte[] exe = File.ReadAllBytes(Path.Combine(path, "GBP.exe"));
            Buffer.BlockCopy(gbRom, 0, exe, OffsetGB, gbRom.Length);
            
            byte[] len = BitConverter.GetBytes(gbRom.Length);
            if (!BitConverter.IsLittleEndian)
                len = len.Reverse().ToArray();            
            Buffer.BlockCopy(len, 0, exe, OffsetLen, len.Length);
            File.WriteAllBytes(Path.Combine(path, title + ".exe"), exe);
            File.Delete(Path.Combine(path, "GBP.exe"));            
        }
    }
}
