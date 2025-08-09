# Minilouguitar

_(name subject to change as I've just made it up)_

A custom oscillator for [Korg Minilogue xd](https://www.korg.com/us/products/synthesizers/minilogue_xd/)
(the code should also work on other [LogueSDK](https://www.korg.com/us/products/synthesizers/minilogue_xd/sdk.php)-compatible synthesizers).
Basic implementation of the [Karplus-Strong plucked string algorithm](https://ccrma.stanford.edu/~jos/pasp/Karplus_Strong_Algorithm.html).

# Usage

## Setup

### lib32-libc

This might not be the case for your distribution, but some Linux distros no
longer support 32-bit binaries shipped with the Logue SDK. In case of Arch
Linux, install
[lib32-glibc](https://archlinux.org/packages/core/x86_64/lib32-glibc/) before
continuing.

### Repo setup

```bash
git submodule update --init --recursive
./logue-sdk/tools/gcc/get_gcc_linux.sh
./logue-sdk/tools/logue-cli/get_logue_cli_linux.sh
```

## Build

```bash
make
```

## Install onto your Minilogue xd

1. Make sure that you've updated your Minilogue to the latest firmware
2. Switch your Minilogue's MIDI channel to 1 (due to [this logue-cli issue](https://github.com/korginc/logue-sdk/issues/43))
3. Follow the instructions obtained by running:

```bash
./logue-sdk/tools/logue-cli/logue-cli-linux64-0.07-2b/logue-cli --help
```
