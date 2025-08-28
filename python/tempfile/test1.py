#!/usr/bin/env  python3

import os
import tempfile

# 環境変数
tmpdir = os.environ.get('TMPDIR')
print(f"{tmpdir=}")

dirname = tempfile.mkdtemp(prefix='hoge-')
print(f"{dirname=}")

os.environ['TMPDIR'] = '/ramdisk/foo/bar'
dirname = tempfile.mkdtemp(prefix='hoge-')
print(f"{dirname=}")
