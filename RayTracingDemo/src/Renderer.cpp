#include "../include/Renderer.h"
#include <iostream>
#include <fstream>
#include <sstream>

Renderer::Renderer():
    imageHeight(256),
    imageWidth(256)
{

}

Renderer::~Renderer()
{

}

bool Renderer::renderPPM()
{
    std::fstream fs;
    std::ostringstream out;

    fs.open("output.ppm", std::ios::out);

    std::cerr << "Start render." << std::flush;
    out << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight - 1; j >= 0; --j) {

        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            auto r = double(i) / (imageWidth - 1);
            auto g = double(j) / (imageHeight - 1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }

    }

    std::cerr << "\nDone.\n";
    std::string outstr = out.str();
    fs.write(outstr.c_str(), outstr.length());
    fs.close();

	return true;
}