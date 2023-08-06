#!/bin/bash

# changing directory to src
    cd src/

# install 'nlohmann JSON for modern C++'
    echo "installing json library."
    git clone https://github.com/nlohmann/json.git
    echo "Moving the necessary directory"
    mv json/single_include/nlohmann/ ./
    rm -rf json/
    echo "done."

# install libcurl
    echo "installing libcurl"
    sudo apt update && apt upgrade
    sudo apt install libcurl4-openssl-dev
    echo "done."