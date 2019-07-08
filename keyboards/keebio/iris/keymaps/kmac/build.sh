#!/bin/bash

readonly SCRIPTNAME=$(basename "$0")
readonly SCRIPTDIR=$(readlink -m "$(dirname "$0")")

help() {
cat<<EOF
Builds/flashes

USAGE:
  $SCRIPTNAME [clean|compile|dfu]

ARGUMENTS:
  clean: clean
  compile: builds the firmware
  dfu: build and flash the firmware

OPTIONS:
  -h|--help: print this help
EOF
exit 1
}
main() {
  target=keebio/iris/rev3:kmac
  while [ $# -gt 0 ] ; do
    case "${1:-""}" in
      -h|--help)
        help
        ;;
      compile)
        break
        ;;
      clean)
        target=keebio/iris/rev3:kmac:clean
        break
        ;;
      dfu)
        target=keebio/iris/rev3:kmac:dfu
        break
        ;;
      *)
        die "Invalid command '$1' [use -h/--help for help]"
        ;;
    esac
    shift
  done

  cd "$SCRIPTDIR/../../../../.."
  echo util/docker_build.sh "$target"
  if util/docker_build.sh "$target"; then
    cd "$SCRIPTDIR"
    ./print-map.sh
  fi
}

# Execute main if script is executed directly (not sourced):
# This allows for shunit2 testing (https://github.com/kward/shunit2)
if [[ "${BASH_SOURCE[0]}" = "$0" ]]; then
  main "$@"
fi
