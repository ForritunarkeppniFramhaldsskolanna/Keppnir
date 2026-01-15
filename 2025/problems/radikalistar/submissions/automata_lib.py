from collections import defaultdict
from typing import (
    Dict,
    Generic,
    Iterable,
    List,
    Set,
    Tuple,
    TypeVar,
)

T = TypeVar("T")


class PartitionRefinement(Generic[T]):
    """Maintain and refine a partition of a set of items into subsets.
    Space usage for a partition of n items is O(n), and each refine operation
    takes time proportional to the size of its argument.

    Adapted from code by D. Eppstein:
    https://www.ics.uci.edu/~eppstein/PADS/PartitionRefinement.py
    """

    __slots__: Tuple[str, ...] = ("_sets", "_partition")

    _sets: Dict[int, Set[T]]
    _partition: Dict[T, int]

    def __init__(self, items: Iterable[T]) -> None:
        """Create a new partition refinement data structure for the given
        items. Initially, all items belong to the same subset.
        """
        S = set(items)
        self._sets = {id(S): S}
        self._partition = {x: id(S) for x in S}

    def get_set_by_id(self, id: int) -> Set[T]:
        """Return the set in the partition corresponding to id."""
        return self._sets[id]

    def get_id(self, x: int):
        """Return the id of set that x belongs to."""
        return self._partition[x]

    def get_set_ids(self) -> Iterable[int]:
        """Return set ids corresponding to the internal partition."""
        return self._sets.keys()

    def get_sets(self) -> Iterable[Set[T]]:
        """Return sets corresponding to the internal partition."""
        return self._sets.values()

    def refine(self, S: Iterable[T]) -> List[Tuple[int, int]]:
        """Refine each set A in the partition to the two sets
        A & S, A - S.  Return a list of pairs ids (id(A & S), id(A - S))
        for each changed set.  Within each pair, A & S will be
        a newly created set, while A - S will be a modified
        version of an existing set in the partition (retaining its old id).
        Not a generator because we need to perform the partition
        even if the caller doesn't iterate through the results.
        """
        hit = defaultdict(set)
        output = []

        for x in S:
            hit[self._partition[x]].add(x)

        for Aid, AintS in hit.items():
            A = self._sets[Aid]

            # Only need to check lengths, we already know AintS is a subset of A
            # by construction
            if len(AintS) < len(A):
                self._sets[id(AintS)] = AintS
                for x in AintS:
                    self._partition[x] = id(AintS)
                A -= AintS
                output.append((id(AintS), Aid))

        return output


if __name__ == "__main__":
    n, q = map(int, input().split())
    partitioning = PartitionRefinement(range(1, n + 1))
    for _ in range(q):
        op, *args = input().split()
        if op == "r":
            m, *x = map(int, args)
            partitioning.refine(x)
        elif op == "s":
            print(len(partitioning.get_set_ids()))
        elif op == "m":
            set_values = partitioning.get_set_by_id(partitioning.get_id(int(args[0])))
            print(" ".join(str(x) for x in set_values))
