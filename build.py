import os
import subprocess
import shutil
import sys

# ------------------------------------------------------------
# PART 1: Build the Project with CMake
# ------------------------------------------------------------

# Define the build directory
build_dir = "build"

# Create the build directory if it does not exist
if not os.path.exists(build_dir):
    os.makedirs(build_dir)
    print(f"Created build directory: {build_dir}")

# Change working directory to the build directory
os.chdir(build_dir)

# Run CMake to configure the project
cmake_command = ["cmake", ".."]
print("Running CMake...")
try:
    subprocess.run(cmake_command, check=True)
    print("CMake configuration completed.")
except subprocess.CalledProcessError as e:
    print(f"Error during CMake configuration: {e}")
    sys.exit(1)

# Build the project using CMake
build_command = ["cmake", "--build", "."]
print("Building the project...")
try:
    subprocess.run(build_command, check=True)
    print("Build completed successfully.")
except subprocess.CalledProcessError as e:
    print(f"Error during build: {e}")
    sys.exit(1)

# ------------------------------------------------------------
# PART 2: Copy the "resources" Folder into Each Directory Containing an Executable
# ------------------------------------------------------------

def is_executable_file(filepath):
    """
    Determine if a file is an executable.
    - On Windows, this checks for a .exe extension.
    - On POSIX systems, it checks if the file has executable permission.
    """
    if os.path.isfile(filepath):
        if os.name == 'nt':
            return filepath.lower().endswith('.exe')
        else:
            return os.access(filepath, os.X_OK)
    return False

def copy_resources_to_dir(target_dir, resources_dir):
    """
    Update the 'resources' folder in target_dir with the files from resources_dir.
    If the destination folder does not exist, copy the entire folder.
    If it does exist, only override files that are already present.
    """
    dest = os.path.join(target_dir, "resources")
    
    # If the destination does not exist, copy the entire folder.
    if not os.path.exists(dest):
        shutil.copytree(resources_dir, dest)
        print(f"Copied resources to: {dest}")
        return

    # Destination exists. Walk through the source resources folder.
    for root, dirs, files in os.walk(resources_dir):
        # Compute the relative path from the source resources folder.
        rel_path = os.path.relpath(root, resources_dir)
        # Determine the corresponding directory in the destination.
        dest_dir = os.path.join(dest, rel_path)
        
        # Only update if the destination directory exists.
        if not os.path.exists(dest_dir):
            print(f"Destination subdirectory does not exist, skipping: {dest_dir}")
            continue

        # Update existing files.
        for file in files:
            src_file = os.path.join(root, file)
            dest_file = os.path.join(dest_dir, file)
            if os.path.exists(dest_file):
                shutil.copy2(src_file, dest_file)
                print(f"Overridden file: {dest_file}")
            else:
                # Skip files that don't already exist in the destination.
                print(f"File does not exist in destination, skipping: {dest_file}")

# Determine the absolute path of the directory where this Python script resides
script_dir = os.path.dirname(os.path.abspath(__file__))

# Assume the "resources" folder is in the same directory as this script
resources_dir = os.path.join(script_dir, "resources")
if not os.path.exists(resources_dir):
    print(f"Error: resources folder not found at: {resources_dir}")
    sys.exit(1)

# We assume that executables are built under the current build directory.
# Traverse the build directory recursively.
start_dir = os.getcwd()  # This is the build directory, thanks to os.chdir(build_dir) above.

for root, dirs, files in os.walk(start_dir):
    # Check if the current folder contains any executable file.
    if any(is_executable_file(os.path.join(root, f)) for f in files):
        copy_resources_to_dir(root, resources_dir)
