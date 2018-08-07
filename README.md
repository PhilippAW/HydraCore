## Hydra Renderer

The Hydra Renderer consists of 3 heads:

- End User Plugin (3ds max or else)
- HydraAPI (infrastructure)
- HydraCore (render engine, compute core)

This repo contain the last one.

# Usage

Windows:
1. Clone HydraAPI repo is some folder (for example 'myfolder/HydraAPI'). 
2. Build HydraAPI with visual studio 2015 or later under windows.
3. Clone HydraCore repo in the same folder (to form 'myfolder/HydraCore').
4. Build HydraCore with visual studio 2015 or later under windows.
5. Set 'inLibraryPath = "tests/test_42";' inside input.cpp; 
6. Set 'inDeviceId = 0' (or other, depends on your OpenCL HW);
7. Set 'inDevelopment = true' inside 'GPUOCLLayer.cpp' to disable internal shader cache (note that nvidia use its' own shader cache!). 
8. If you want to fly around scene set 'm_screen.m_cpuFrameBuffer = false;' to enable gpu frame buffer.
9. Press 'P' for Path Tracing, 'L' for light tracing and 'B' for IBPT.

Linux:
1. Clone HydraAPI repo is some folder (for example 'myfolder/HydraAPI'). 
2. Build HydraAPI with Cmake.
3. Clone HydraCore repo in the same folder (to form 'myfolder/HydraCore').
4. Build HydraCore with Cmake.
5. Set 'Input::inLibraryPath = "tests/test_42";' inside input.cpp; 
6. Set 'Input::inDeviceId    = 0' (or other, depends on your OpenCL HW); 
7. Set 'inDevelopment = true' inside 'GPUOCLLayer.cpp' to disable internal shader cache (note that nvidia use its' own shader cache!).
8. If you want to fly around scene set 'm_screen.m_cpuFrameBuffer = false;' to enable gpu frame buffer.
9. Press 'P' for Path Tracing, 'L' for light tracing and 'B' for IBPT.

Or to install the renderer core on Linux:
1. Clone HydraAPI repo is some folder (for example 'myfolder/HydraAPI'). 
2. Build HydraAPI with Cmake.
3. Clone HydraCore repo in the same folder (to form 'myfolder/HydraCore').
4. Use the following command to build and install HydraCore (for example from 'myfolder/HydraCore/build')   
cmake -DCMAKE_INSTALL_PREFIX=/home/YourUserName .. && make all install

# Core command line by examples

* simple image render
* hydra -inputlib "tests/test_42" -out "/home/frol/temp/z_out.png" -nowindow 1 

* simple image render (rendertarget statefile tests/test_42/statex_00012.xml)
* hydra -inputlib "tests/test_42" -statefile "statex_00012.xml" -out "/home/frol/temp/z_out.png" -nowindow 1 

* rendering on 2 GPUs via OS shared memory (commands were generated by HyrdaAPI)
* hydra -nowindow 1 -inputlib "tests/test_42" -width 1024 -height 768 -cpu_fb 0 -sharedimage hydraimage_1533639330288 -cl_device_id 0
* hydra -nowindow 1 -inputlib "tests/test_42" -width 1024 -height 768 -cpu_fb 0 -sharedimage hydraimage_1533639330288 -cl_device_id 1


# Licence and dependency

HydraCore uses MIT licence itself, however it depends on the other software as follows (see doc/licence directory):

* 02 - FreeImage Public License - Version 1.0 (FreeImage is used in the form of binaries)
* 03 - Embree Apache License 2.0 (Embree is used in the form of binaries)
* 04 - xxhash BSD 3-clause "New" or "Revised" (xxhash is used in the form of sources)
* 05 - pugixml MIT licence (pugixml is used in the form of sources)
* 06 - clew Boost Software License - Version 1.0 - August 17th, 2003 (clew is used in the form of sources)
* 07 - IESNA MIT-like licence (IESNA used in the form of sources)
* 08 - glad MIT licence (glad is used in form of generated source code).
* 09 - glfw BSD-like license (glfw is used in form of binaries only for demonstration purposes).

Most of them are simple MIT-like-licences without any serious restrictions. 
So in general there should be no problem to use HydraCore in your open source or commercial projects. 

However if you find that for some reason you can't use one of these components, please let us know!
Most of these components can be replaced.

# Acknowlegments
This project is supported by RFBR 16-31-60048 "mol_a_dk".
