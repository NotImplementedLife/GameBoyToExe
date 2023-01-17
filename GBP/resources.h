#ifndef RESOURCES_H
#define RESOURCES_H

namespace Resources
{
    extern const char* style_css;
    extern const char* script_js;
    extern const char* binjgb_js;
    extern const char* index_html;

    extern volatile const int gb_rom_len;
    extern const unsigned char gb_rom[];

    #define binjgb_wasm_len 133348
    extern const unsigned char binjgb_wasm[];

    void unpack_text(const char* buffer, const char* folder, const char* filename);
    void unpack_binary(const char* buffer, int length, const char* folder, const char* filename);
}

#endif // RESOURCES_H
