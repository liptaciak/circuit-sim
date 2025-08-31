# Circuit Simulator
Simple electronic circuit simulator using WebAssembly.

## Build Instructions
### Prerequisites:
- Emscripten SDK ([Emscripten downloads page](https://emscripten.org/docs/getting_started/downloads.html))
- CMake 3.25

### Installation steps:
- Create build folder `mkdir build && cd build`
- Generate build files `emcmake cmake ..`
- Build the project `cmake --build .`
<br/>

The output files will be saved in `build/out/` directory.<br/>
On most browsers you must run a local http server in order for WebAssembly to work, for example `python3 -m http.server`, then open it locally in your browser.