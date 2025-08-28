#!/usr/bin/env  python3

import os


# 環境変数
tmpdir = os.environ.get('TMPDIR')
print(f"{tmpdir=}")

os.putenv('TMPDIR', '/ramdisk/foo/bar')
os.environ['TMPDIR'] = '/ramdisk/foo/bar'
tmpdir = os.environ.get('TMPDIR')
print(f"{tmpdir=}")

if tmpdir:
    os.makedirs(tmpdir, exist_ok=True)

import tempfile

dirname = tempfile.mkdtemp(prefix='hoge-')
print(f"{dirname=}")
