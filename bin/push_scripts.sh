#!/usr/bin/env bash
# Push bin files to both servers
rsync -rtp --delete $HOME/bin/ www_deploy@860elwb01:./bin
rsync -rtp --delete $HOME/bin/ www_deploy@860elwb02:./bin
rsync -rtp --delete $HOME/etc/ www_deploy@860elwb01:./etc
rsync -rtp --delete $HOME/etc/ www_deploy@860elwb02:./etc
