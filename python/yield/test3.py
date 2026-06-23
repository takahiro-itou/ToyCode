#!python3

import sys

class  YieldTester:

    def __init__(self):
        self._packs = []
        self._num_yields = 0
        pass

    def test(self, val):
        print(f"CALL test {val=}")
        self._packs.append(val)
        if len(self._packs) >= 3:
            self._num_yields += 1
            print(
                f"yield {self._packs=}, {self._num_yields=}",
                file=sys.stderr)
            yield  self._packs
            self._packs = []
        # End If
    # End Def (test)

# End Class (YieldTester)


class  MyIterator:

    def __init__(self, it):
        self._tester = YieldTester()
        self._it = iter(it)
        self._work = self.get_next_iterator()

    def __iter__(self):
        return  self

    def __next__(self):
        while True:
            try:
                return  next(self._work)
            except  StopIteration:
                print(f"Exausted", file=sys.stderr)
                pass

            try:
                self._work = self.get_next_iterator()
            except  StopIteration:
                print("All Finish", file=sys.stderr)
                raise  StopIteration
        # End While

    def get_next_iterator(self):
        val = next(self._it)
        print(f"MyIterator::__next__ {val=}", file=sys.stderr)
        yield from  self._tester.test(val)

# End Class (MyIterator)


counter = 0
myit = MyIterator(range(10))

for x in myit:
    counter += 1
    print(f"MAIN : {counter=}, {x=}")
    if (counter >= 20):
        break
# Next (i)
