#!/bin/bash

set -e


TARGET_FOLDERS=(
    "afr"
    "button_swap" 
    "fliprate_remover" 
    "force_30_fps" 
    "frame_logger" 
    "gamepad_helper" 
)

echo -e "Starting build process..."

cd plugin_src/

mkdir -p bin

for folder in "${TARGET_FOLDERS[@]}"; do
    if [ -d "$folder" ]; then
        echo -e "Building in: $folder..."
        
        (cd "$folder" && make -j$(nproc) && cp "$folder.elf" ../bin)
        
        if [ $? -eq 0 ]; then
            echo -e "Successfully built $folder"
        else
            echo -e "Failed to build $folder}"
            exit 1
        fi
    else
        echo -e "Directory $folder not found, skipping..."
    fi
done

echo -e "All builds finished!"