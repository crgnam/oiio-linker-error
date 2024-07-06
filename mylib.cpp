#include "mylib.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

#include "OpenImageIO/imageio.h"
#include "OpenImageIO/imagebuf.h"

namespace mylib {
    void getImageDimensions(const std::string& filepath)
    {
        // Open the file:
        auto inp = OIIO::ImageInput::open(filepath);
        if (!inp) {
            throw std::runtime_error("OpenImageIO could not open: " + filepath);
        };

        const OIIO::ImageSpec& spec = inp->spec();
        int width = spec.width;
        int height = spec.height;
        int channels = spec.nchannels;

        std::cout << width << " x " << height << " x " << channels << "\n";
    };
};