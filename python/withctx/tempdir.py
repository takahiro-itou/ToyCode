#!/bin/python3

import tempfile
import time


class  MyTempDir(object):

    def __init__(self, suffix=None, prefix=None, dir=None,
                 ignore_cleanup_errors=False, *, delete=True):
        self._temp_dir = tempfile.TemporaryDirectory(
            suffix = suffix, prefix = prefix, dir = dir,
            ignore_cleanup_errors = ignore_cleanup_errors,
        )

    def __enter__(self):
        return  self._temp_dir.__enter__()

    def __exit__(self, *args):
        self._temp_dir.__exit__(*args)

# End Class (MyTempDir)


with MyTempDir(
        suffix='abc', prefix='test',  dir='.',
) as my_temp_dir:
    print(my_temp_dir)
    time.sleep(10)
# End With
