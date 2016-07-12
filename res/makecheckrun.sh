#!/bin/bash
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"src/EngineCoreLib/"
export LD_LIBRARY_PATH
exec make check
