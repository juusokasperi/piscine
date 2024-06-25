#! /bin/bash
ip -a link | grep ether | cut -b 16-32
