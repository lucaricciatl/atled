import os
import subprocess

# Define the build directory
build_dir = "build"

# Check if the build directory exists, if not, create it
if not os.path.exists(build_dir):
    os.makedirs(build_dir)
    print(f"Created build directory: {build_dir}")

# Change to the build directory
os.chdir(build_dir)

# Run CMake to configure the project
cmake_command = ["cmake", ".."]
print("Running CMake...")
try:
    subprocess.run(cmake_command, check=True)
    print("CMake configuration completed.")
except subprocess.CalledProcessError as e:
    print(f"Error during CMake configuration: {e}")
    exit(1)

# Build the project using CMake
build_command = ["cmake", "--build", "."]
print("Building the project...")
try:
    subprocess.run(build_command, check=True)
    print("Build completed successfully.")
except subprocess.CalledProcessError as e:
    print(f"Error during build: {e}")
    exit(1)
