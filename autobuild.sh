set -Eeuo pipefail

log() {
  echo ">>> $*"
}

build_and_run() {
  log Building...
  make

  log Sending to minilogue...
  ./logue-sdk/tools/logue-cli/logue-cli-linux64-0.07-2b/logue-cli load -i 2 -o 2 -s 0 -u phosc.mnlgxdunit

  log Refreshing the multi-engine
  amidi -p hw:1,0,1 -S "B06708"
  amidi -p hw:1,0,1 -S "B06700"
  sleep 2

  log Playing a sample tune
  amidi -p hw:1,0,1 -S "903E7F"
  sleep .3
  amidi -p hw:1,0,1 -S "803E40"
  sleep .3
  amidi -p hw:1,0,1 -S "90427F"
  sleep .3
  amidi -p hw:1,0,1 -S "804240"
  sleep .3
  amidi -p hw:1,0,1 -S "90457F"
  sleep .3
  amidi -p hw:1,0,1 -S "804540"
  sleep .5
  amidi -p hw:1,0,1 -S "903E7F"
  sleep .1
  amidi -p hw:1,0,1 -S "90427F"
  sleep .1
  amidi -p hw:1,0,1 -S "90457F"
  sleep 2
  amidi -p hw:1,0,1 -S "804240"
  sleep .1
  amidi -p hw:1,0,1 -S "803E40"
  sleep .1
  amidi -p hw:1,0,1 -S "804540"
  sleep .1
}


build_and_run

