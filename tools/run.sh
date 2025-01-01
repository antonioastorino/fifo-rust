#!/usr/bin/env zsh

set -ue

mkdir -p artifacts
RUST_LOG=info cargo run
