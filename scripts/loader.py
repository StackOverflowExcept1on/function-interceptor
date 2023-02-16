#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# pip3 install frida

import argparse
import frida
import os
import time

parser = argparse.ArgumentParser(description="simple injector with frida framework")
parser.add_argument("pid", type=int)
parser.add_argument("library")
args = parser.parse_args()

stopped = False

def on_message(_message, _data):
    global stopped
    stopped = True

session = frida.attach(args.pid)

with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "script.js"), "r") as file:
    script = session.create_script(file.read())

script.on("message", on_message)
script.load()
script.post({"type": "input", "library": os.path.abspath(args.library)})

try:
    while not stopped:
        time.sleep(1)

    session.detach()
except KeyboardInterrupt:
    pass
