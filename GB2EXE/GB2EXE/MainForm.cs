using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GB2EXE
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            //Worker.DecompressGBP("build");            
        }

        private void GBPathButton_Click(object sender, EventArgs e)
        {
            if(OFD.ShowDialog()==DialogResult.OK)
            {
                GBPathInput.Text = OFD.FileName;
                TitleInput.Text = Path.GetFileNameWithoutExtension(OFD.FileName);
            }
        }

        private void ConvertButton_Click(object sender, EventArgs e)
        {
            BgWorker.RunWorkerAsync();
        }

        private void ReportOutput(string msg)
        {
            Invoke(new Action(() =>
            {
                Output.Text += msg + Environment.NewLine;
            }));
        }

        private void BgWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            var path = Path.Combine("build", TitleInput.Text);
            if (Directory.Exists(path))
                Directory.Delete(path, true);
            ReportOutput("Decompressing GB Player...");            
            Worker.DecompressGBP(path);
            ReportOutput("Preparing EXE...");
            Worker.EditGBPExecutable(path, TitleInput.Text, File.ReadAllBytes(GBPathInput.Text));
            ReportOutput("Done");

            Process.Start(path);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            ReportOutput("Output:");
        }
    }
}
