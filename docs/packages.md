# C÷ packages and release downloads

C÷ uses two GitHub distribution channels for different kinds of downloads.

## Releases

The [Releases page](https://github.com/floppylib/C-Divide/releases) is the normal download location for end users. A successful release workflow attaches:

- `cdivide-linux-x64.tar.gz` — Linux x64 compiler and documentation.
- `cdivide-windows-x64.zip` — Windows x64 compiler and documentation.
- `SHA256SUMS` — checksums for the platform archives.

These are host-native compiler tools. They do not currently provide cross-compilation to another operating system.

## GitHub Packages

The release workflow is configured to publish a container image to GitHub Container Registry:

`ghcr.io/floppylib/c-divide`

The image contains the C÷ compiler and the host C++20 toolchain used by the current native preview. It is intended for CI jobs, reproducible command-line use, and trying C÷ without installing the compiler locally.

Pull the image:

~~~sh
docker pull ghcr.io/floppylib/c-divide:latest
~~~

Check a source file in the current directory:

~~~sh
docker run --rm \
  -v "$PWD:/workspace" \
  -w /workspace \
  ghcr.io/floppylib/c-divide:latest \
  check examples/hello.cdiv
~~~

Build a native executable for the container's Linux environment:

~~~sh
docker run --rm \
  -v "$PWD:/workspace" \
  -w /workspace \
  ghcr.io/floppylib/c-divide:latest \
  build examples/hello.cdiv -o build/hello
~~~

On Windows PowerShell, replace `$PWD` with ${PWD} in the volume mapping.

## Publishing

A maintainer can publish the first version from GitHub:

1. Open **Actions** in the repository.
2. Select **C÷ release and packages**.
3. Choose **Run workflow** on the `main` branch.
4. Enter the version tag, for example `v0.2.1`.

The workflow builds and tests Linux and Windows compiler archives before it creates the GitHub Release. It then builds and pushes the container image to GHCR. The package does not exist until this workflow has completed successfully.

The first GHCR publication may be private by default. To allow anonymous public pulls, open the C÷ package page, go to **Package settings**, and change package visibility to **Public**. Do not publish a public package until the image and its contents have been reviewed.

A tag push matching `v*` also runs the same publication workflow.

## Current limitations

- The compiler is still an early native-backend preview.
- The container image is Linux-based and produces executables for the container host environment.
- Windows and Linux compiler archives are built separately; a universal cross-compiler is not yet available.
- The package manager for C÷ source dependencies is a future language feature. GHCR currently distributes the compiler toolchain image, not C÷ libraries.
