# GISM

Small tool for graph isomorphism problem.

## Dependencies

Install emsdk portable https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

Run this and wait for several hours:
``./emsdk install --build=Release sdk-incoming-64bit binaryen-master-64bit``

Finally:
``./emsdk activate --global --build=Release sdk-incoming-64bit binaryen-master-64bit``

Run this:
``source ./emsdk_env.sh``

https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm

## Compilation

``make wasm``

## Running in the 90's

``emrun index.html``