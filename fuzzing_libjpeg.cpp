#include <iostream>
#include "./libjpeg-turbo/turbojpeg.h"
#include <experimental/filesystem>
#include <fstream>

using namespace std;

#define width1 1920
#define height1 1080
#define COLOR_COMPONENTS 3
using namespace std; 
unsigned char buffer[width1 * height1 * COLOR_COMPONENTS]; //!< Contains the uncompressed image


void read_file_content(FILE* stream, unsigned char* output_buf, size_t buf_size, size_t num_byte_to_read)
{
    if (num_byte_to_read < buf_size)
    {
        fread(output_buf, sizeof(unsigned char), num_byte_to_read, stream);
    }

}

size_t get_file_size(char* file_path)
{
    std::filesystem::path p{ file_path };

    return  std::filesystem::file_size(p);
}

int main(int argc, char * argv[])
{
    int JPEG_QUALITY = 75;
    unsigned long _jpegSize = 0;
    unsigned char* _compressedImage = NULL; //!< Memory is allocated by tjCompress2 if _jpegSize == 0;
    FILE* stream;

    tjhandle _jpegCompressor = tjInitCompress();

#if 0
    stream = fopen(argv[1], "r");
    fread(&buffer, sizeof(char), 1, stream);
    fclose(stream);
#else
    stream = fopen(argv[1], "rb");
    size_t file_size = get_file_size(argv[1]);
    read_file_content(stream, buffer, sizeof(buffer), file_size);
    fclose(stream);
    int result = tjCompress2(_jpegCompressor, buffer, width1, 0, height1, TJPF_RGB,
        &_compressedImage, &_jpegSize, TJSAMP_444, JPEG_QUALITY,
        TJFLAG_FASTDCT);
    int nu1 = 8;
#endif
/*
    if (result == 0)
    {
        ofstream myfile;
        myfile.open("C:\\Users\\uie14269\\Desktop\\fuzzing_libjpeg\\x64\\Debug\\example.txt", ios_base::app);
        myfile << "success.\n";
        myfile.close();
    }
    else
    {
        ofstream myfile;
        myfile.open("C:\\Users\\uie14269\\Desktop\\fuzzing_libjpeg\\x64\\Debug\\example.txt", ios_base::app);
        myfile << "fail.\n";
        myfile.close();
    };
 */
    if (result == 0)
    {
        printf("success");
    }
    else
    {
        printf("failed");
    };
    tjDestroy(_jpegCompressor);

    //to free the memory allocated by TurboJPEG (either by tjAlloc(), 
    //or by the Compress/Decompress) after you are done working on it:
    tjFree(_compressedImage);
}
