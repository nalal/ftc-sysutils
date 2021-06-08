#!/bin/bash
cd src/cpp/
make install -j $(nproc)
cd ../scripts
cp shell/* /bin/
