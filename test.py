from kerneltree import IntervalTree

it = IntervalTree()

it.add(1, 5, 7)
# print("First inserted")
it.add(2, 3, 4)

it.print_region(0, 4)