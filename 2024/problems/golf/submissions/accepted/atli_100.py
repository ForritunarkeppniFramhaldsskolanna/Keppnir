#!/usr/bin/python3

import sys

from bisect import bisect_left,bisect_right,insort
from itertools import chain,repeat,starmap
from math import log
from operator import add,eq,ne,gt,ge,lt,le,iadd,itemgetter
from textwrap import dedent
from collections.abc import Sequence,MutableSequence,MutableSet,Set
from functools import wraps,reduce,cmp_to_key
class SortedList(MutableSequence):
	DEFAULT_LOAD_FACTOR=1000
	def __init__(A,iterable=None,key=None):
		B=iterable;A._len=0;A._load=A.DEFAULT_LOAD_FACTOR;A._lists=[];A._maxes=[];A._index=[];A._offset=0
		if B is not None:A._update(B)
	def __new__(A,iterable=None,key=None):
		if key is None:return object.__new__(A)
		elif A is SortedList:return object.__new__(SortedKeyList)
		else:raise TypeError('inherit SortedKeyList for key argument')
	@property
	def key(self):0
	def _reset(A,load):B=reduce(iadd,A._lists,[]);A._clear();A._load=load;A._update(B)
	def clear(A):A._len=0;del A._lists[:];del A._maxes[:];del A._index[:];A._offset=0
	_clear=clear
	def add(D,value):
		A=value;E=D._lists;C=D._maxes
		if C:
			B=bisect_right(C,A)
			if B==len(C):B-=1;E[B].append(A);C[B]=A
			else:insort(E[B],A)
			D._expand(B)
		else:E.append([A]);C.append(A)
		D._len+=1
	def _expand(B,pos):
		A=pos;E=B._load;F=B._lists;C=B._index
		if len(F[A])>E<<1:H=B._maxes;G=F[A];I=G[E:];del G[E:];H[A]=G[-1];F.insert(A+1,I);H.insert(A+1,I[-1]);del C[:]
		elif C:
			D=B._offset+A
			while D:C[D]+=1;D=D-1>>1
			C[0]+=1
	def update(A,iterable):
		C=A._lists;D=A._maxes;B=sorted(iterable)
		if D:
			if len(B)*4>=A._len:C.append(B);B=reduce(iadd,C,[]);B.sort();A._clear()
			else:
				F=A.add
				for G in B:F(G)
				return
		E=A._load;C.extend(B[A:A+E]for A in range(0,len(B),E));D.extend(A[-1]for A in C);A._len=len(B);del A._index[:]
	_update=update
	def __contains__(D,value):
		A=value;B=D._maxes
		if not B:return False
		C=bisect_left(B,A)
		if C==len(B):return False
		E=D._lists;F=bisect_left(E[C],A);return E[C][F]==A
	def discard(B,value):
		C=value;D=B._maxes
		if not D:return
		A=bisect_left(D,C)
		if A==len(D):return
		E=B._lists;F=bisect_left(E[A],C)
		if E[A][F]==C:B._delete(A,F)
	def remove(C,value):
		A=value;D=C._maxes
		if not D:raise ValueError('{0!r} not in list'.format(A))
		B=bisect_left(D,A)
		if B==len(D):raise ValueError('{0!r} not in list'.format(A))
		E=C._lists;F=bisect_left(E[B],A)
		if E[B][F]==A:C._delete(B,F)
		else:raise ValueError('{0!r} not in list'.format(A))
	def _delete(B,pos,idx):
		A=pos;C=B._lists;D=B._maxes;E=B._index;F=C[A];del F[idx];B._len-=1;I=len(F)
		if I>B._load>>1:
			D[A]=F[-1]
			if E:
				G=B._offset+A
				while G>0:E[G]-=1;G=G-1>>1
				E[0]-=1
		elif len(C)>1:
			if not A:A+=1
			H=A-1;C[H].extend(C[A]);D[H]=C[H][-1];del C[A];del D[A];del E[:];B._expand(H)
		elif I:D[A]=F[-1]
		else:del C[A];del D[A];del E[:]
	def _loc(B,pos,idx):
		'Convert an index pair (lists index, sublist index) into a single\n        index number that corresponds to the position of the value in the\n        sorted list.\n\n        Many queries require the index be built. Details of the index are\n        described in ``SortedList._build_index``.\n\n        Indexing requires traversing the tree from a leaf node to the root. The\n        parent of each node is easily computable at ``(pos - 1) // 2``.\n\n        Left-child nodes are always at odd indices and right-child nodes are\n        always at even indices.\n\n        When traversing up from a right-child node, increment the total by the\n        left-child node.\n\n        The final index is the sum from traversal and the index in the sublist.\n\n        For example, using the index from ``SortedList._build_index``::\n\n            _index = 14 5 9 3 2 4 5\n            _offset = 3\n\n        Tree::\n\n                 14\n              5      9\n            3   2  4   5\n\n        Converting an index pair (2, 3) into a single index involves iterating\n        like so:\n\n        1. Starting at the leaf node: offset + alpha = 3 + 2 = 5. We identify\n           the node as a left-child node. At such nodes, we simply traverse to\n           the parent.\n\n        2. At node 9, position 2, we recognize the node as a right-child node\n           and accumulate the left-child in our total. Total is now 5 and we\n           traverse to the parent at position 0.\n\n        3. Iteration ends at the root.\n\n        The index is then the sum of the total and sublist index: 5 + 3 = 8.\n\n        :param int pos: lists index\n        :param int idx: sublist index\n        :return: index in sorted list\n\n        ';A=pos
		if not A:return idx
		C=B._index
		if not C:B._build_index()
		D=0;A+=B._offset
		while A:
			if not A&1:D+=C[A-1]
			A=A-1>>1
		return D+idx
	def _pos(B,idx):
		'Convert an index into an index pair (lists index, sublist index)\n        that can be used to access the corresponding lists position.\n\n        Many queries require the index be built. Details of the index are\n        described in ``SortedList._build_index``.\n\n        Indexing requires traversing the tree to a leaf node. Each node has two\n        children which are easily computable. Given an index, pos, the\n        left-child is at ``pos * 2 + 1`` and the right-child is at ``pos * 2 +\n        2``.\n\n        When the index is less than the left-child, traversal moves to the\n        left sub-tree. Otherwise, the index is decremented by the left-child\n        and traversal moves to the right sub-tree.\n\n        At a child node, the indexing pair is computed from the relative\n        position of the child node as compared with the offset and the remaining\n        index.\n\n        For example, using the index from ``SortedList._build_index``::\n\n            _index = 14 5 9 3 2 4 5\n            _offset = 3\n\n        Tree::\n\n                 14\n              5      9\n            3   2  4   5\n\n        Indexing position 8 involves iterating like so:\n\n        1. Starting at the root, position 0, 8 is compared with the left-child\n           node (5) which it is greater than. When greater the index is\n           decremented and the position is updated to the right child node.\n\n        2. At node 9 with index 3, we again compare the index to the left-child\n           node with value 4. Because the index is the less than the left-child\n           node, we simply traverse to the left.\n\n        3. At node 4 with index 3, we recognize that we are at a leaf node and\n           stop iterating.\n\n        4. To compute the sublist index, we subtract the offset from the index\n           of the leaf node: 5 - 3 = 2. To compute the index in the sublist, we\n           simply use the index remaining from iteration. In this case, 3.\n\n        The final index pair from our example is (2, 3) which corresponds to\n        index 8 in the sorted list.\n\n        :param int idx: index in sorted list\n        :return: (lists index, sublist index) pair\n\n        ';A=idx
		if A<0:
			F=len(B._lists[-1])
			if-A<=F:return len(B._lists)-1,F+A
			A+=B._len
			if A<0:raise IndexError('list index out of range')
		elif A>=B._len:raise IndexError('list index out of range')
		if A<len(B._lists[0]):return 0,A
		E=B._index
		if not E:B._build_index()
		D=0;C=1;H=len(E)
		while C<H:
			G=E[C]
			if A<G:D=C
			else:A-=G;D=C+1
			C=(D<<1)+1
		return D-B._offset,A
	def _build_index(A):
		'Build a positional index for indexing the sorted list.\n\n        Indexes are represented as binary trees in a dense array notation\n        similar to a binary heap.\n\n        For example, given a lists representation storing integers::\n\n            0: [1, 2, 3]\n            1: [4, 5]\n            2: [6, 7, 8, 9]\n            3: [10, 11, 12, 13, 14]\n\n        The first transformation maps the sub-lists by their length. The\n        first row of the index is the length of the sub-lists::\n\n            0: [3, 2, 4, 5]\n\n        Each row after that is the sum of consecutive pairs of the previous\n        row::\n\n            1: [5, 9]\n            2: [14]\n\n        Finally, the index is built by concatenating these lists together::\n\n            _index = [14, 5, 9, 3, 2, 4, 5]\n\n        An offset storing the start of the first row is also stored::\n\n            _offset = 3\n\n        When built, the index can be used for efficient indexing into the list.\n        See the comment and notes on ``SortedList._pos`` for details.\n\n        ';B=list(map(len,A._lists))
		if len(B)==1:A._index[:]=B;A._offset=0;return
		D=iter(B);F=iter(D);C=list(starmap(add,zip(D,F)))
		if len(B)&1:C.append(B[-1])
		if len(C)==1:A._index[:]=C+B;A._offset=1;return
		G=2**(int(log(len(C)-1,2))+1);C.extend(repeat(0,G-len(C)));E=[B,C]
		while len(E[-1])>1:D=iter(E[-1]);F=iter(D);H=list(starmap(add,zip(D,F)));E.append(H)
		reduce(iadd,reversed(E),A._index);A._offset=G*2-1
	def __delitem__(A,index):
		"Remove value at `index` from sorted list.\n\n        ``sl.__delitem__(index)`` <==> ``del sl[index]``\n\n        Supports slicing.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> del sl[2]\n        >>> sl\n        SortedList(['a', 'b', 'd', 'e'])\n        >>> del sl[:2]\n        >>> sl\n        SortedList(['d', 'e'])\n\n        :param index: integer or slice for indexing\n        :raises IndexError: if index out of range\n\n        ";C=index
		if isinstance(C,slice):
			D,B,E=C.indices(A._len)
			if E==1 and D<B:
				if D==0 and B==A._len:return A._clear()
				elif A._len<=8*(B-D):
					I=A._getitem(slice(None,D))
					if B<A._len:I+=A._getitem(slice(B,None))
					A._clear();return A._update(I)
			F=range(D,B,E)
			if E>0:F=reversed(F)
			J,K=A._pos,A._delete
			for C in F:G,H=J(C);K(G,H)
		else:G,H=A._pos(C);A._delete(G,H)
	def __getitem__(B,index):
		"Lookup value at `index` in sorted list.\n\n        ``sl.__getitem__(index)`` <==> ``sl[index]``\n\n        Supports slicing.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> sl[1]\n        'b'\n        >>> sl[-1]\n        'e'\n        >>> sl[2:5]\n        ['c', 'd', 'e']\n\n        :param index: integer or slice for indexing\n        :return: value or list of values\n        :raises IndexError: if index out of range\n\n        ";C=index;A=B._lists
		if isinstance(C,slice):
			E,D,I=C.indices(B._len)
			if I==1 and E<D:
				if E==0 and D==B._len:return reduce(iadd,B._lists,[])
				J,K=B._pos(E);L=A[J];F=K+D-E
				if len(L)>=F:return L[K:F]
				if D==B._len:H=len(A)-1;F=len(A[H])
				else:H,F=B._pos(D)
				N=A[J][K:];O=A[J+1:H];G=reduce(iadd,O,N);G+=A[H][:F];return G
			if I==-1 and E>D:G=B._getitem(slice(D+1,E+1));G.reverse();return G
			P=range(E,D,I);return list(B._getitem(A)for A in P)
		else:
			if B._len:
				if C==0:return A[0][0]
				elif C==-1:return A[-1][-1]
			else:raise IndexError('list index out of range')
			if 0<=C<len(A[0]):return A[0][C]
			M=len(A[-1])
			if-M<C<0:return A[-1][M+C]
			Q,R=B._pos(C);return A[Q][R]
	_getitem=__getitem__
	def __setitem__(B,index,value):'Raise not-implemented error.\n\n        ``sl.__setitem__(index, value)`` <==> ``sl[index] = value``\n\n        :raises NotImplementedError: use ``del sl[index]`` and\n            ``sl.add(value)`` instead\n\n        ';A='use ``del sl[index]`` and ``sl.add(value)`` instead';raise NotImplementedError(A)
	def __iter__(A):'Return an iterator over the sorted list.\n\n        ``sl.__iter__()`` <==> ``iter(sl)``\n\n        Iterating the sorted list while adding or deleting values may raise a\n        :exc:`RuntimeError` or fail to iterate over all values.\n\n        ';return chain.from_iterable(A._lists)
	def __reversed__(A):'Return a reverse iterator over the sorted list.\n\n        ``sl.__reversed__()`` <==> ``reversed(sl)``\n\n        Iterating the sorted list while adding or deleting values may raise a\n        :exc:`RuntimeError` or fail to iterate over all values.\n\n        ';return chain.from_iterable(map(reversed,reversed(A._lists)))
	def reverse(A):'Raise not-implemented error.\n\n        Sorted list maintains values in ascending sort order. Values may not be\n        reversed in-place.\n\n        Use ``reversed(sl)`` for an iterator over values in descending sort\n        order.\n\n        Implemented to override `MutableSequence.reverse` which provides an\n        erroneous default implementation.\n\n        :raises NotImplementedError: use ``reversed(sl)`` instead\n\n        ';raise NotImplementedError('use ``reversed(sl)`` instead')
	def islice(A,start=None,stop=None,reverse=False):
		"Return an iterator that slices sorted list from `start` to `stop`.\n\n        The `start` and `stop` index are treated inclusive and exclusive,\n        respectively.\n\n        Both `start` and `stop` default to `None` which is automatically\n        inclusive of the beginning and end of the sorted list.\n\n        When `reverse` is `True` the values are yielded from the iterator in\n        reverse order; `reverse` defaults to `False`.\n\n        >>> sl = SortedList('abcdefghij')\n        >>> it = sl.islice(2, 6)\n        >>> list(it)\n        ['c', 'd', 'e', 'f']\n\n        :param int start: start index (inclusive)\n        :param int stop: stop index (exclusive)\n        :param bool reverse: yield values in reverse order\n        :return: iterator\n\n        ";C=start;B=stop;D=A._len
		if not D:return iter(())
		C,B,J=slice(C,B).indices(A._len)
		if C>=B:return iter(())
		E=A._pos;H,I=E(C)
		if B==D:F=len(A._lists)-1;G=len(A._lists[-1])
		else:F,G=E(B)
		return A._islice(H,I,F,G,reverse)
	def _islice(M,min_pos,min_idx,max_pos,max_idx,reverse):
		'Return an iterator that slices sorted list using two index pairs.\n\n        The index pairs are (min_pos, min_idx) and (max_pos, max_idx), the\n        first inclusive and the latter exclusive. See `_pos` for details on how\n        an index is converted to an index pair.\n\n        When `reverse` is `True`, values are yielded from the iterator in\n        reverse order.\n\n        ';H=reverse;G=max_idx;F=min_idx;C=max_pos;B=min_pos;A=M._lists
		if B>C:return iter(())
		if B==C:
			if H:I=reversed(range(F,G));return map(A[B].__getitem__,I)
			I=range(F,G);return map(A[B].__getitem__,I)
		J=B+1
		if J==C:
			if H:D=range(F,len(A[B]));E=range(G);return chain(map(A[C].__getitem__,reversed(E)),map(A[B].__getitem__,reversed(D)))
			D=range(F,len(A[B]));E=range(G);return chain(map(A[B].__getitem__,D),map(A[C].__getitem__,E))
		if H:D=range(F,len(A[B]));K=range(J,C);L=map(A.__getitem__,reversed(K));E=range(G);return chain(map(A[C].__getitem__,reversed(E)),chain.from_iterable(map(reversed,L)),map(A[B].__getitem__,reversed(D)))
		D=range(F,len(A[B]));K=range(J,C);L=map(A.__getitem__,K);E=range(G);return chain(map(A[B].__getitem__,D),chain.from_iterable(L),map(A[C].__getitem__,E))
	def irange(H,minimum=None,maximum=None,inclusive=(True,True),reverse=False):
		"Create an iterator of values between `minimum` and `maximum`.\n\n        Both `minimum` and `maximum` default to `None` which is automatically\n        inclusive of the beginning and end of the sorted list.\n\n        The argument `inclusive` is a pair of booleans that indicates whether\n        the minimum and maximum ought to be included in the range,\n        respectively. The default is ``(True, True)`` such that the range is\n        inclusive of both minimum and maximum.\n\n        When `reverse` is `True` the values are yielded from the iterator in\n        reverse order; `reverse` defaults to `False`.\n\n        >>> sl = SortedList('abcdefghij')\n        >>> it = sl.irange('c', 'f')\n        >>> list(it)\n        ['c', 'd', 'e', 'f']\n\n        :param minimum: minimum value to start iterating\n        :param maximum: maximum value to stop iterating\n        :param inclusive: pair of booleans\n        :param bool reverse: yield values in reverse order\n        :return: iterator\n\n        ";J=inclusive;F=maximum;E=minimum;B=H._maxes
		if not B:return iter(())
		C=H._lists
		if E is None:D=0;I=0
		elif J[0]:
			D=bisect_left(B,E)
			if D==len(B):return iter(())
			I=bisect_left(C[D],E)
		else:
			D=bisect_right(B,E)
			if D==len(B):return iter(())
			I=bisect_right(C[D],E)
		if F is None:A=len(B)-1;G=len(C[A])
		elif J[1]:
			A=bisect_right(B,F)
			if A==len(B):A-=1;G=len(C[A])
			else:G=bisect_right(C[A],F)
		else:
			A=bisect_left(B,F)
			if A==len(B):A-=1;G=len(C[A])
			else:G=bisect_left(C[A],F)
		return H._islice(D,I,A,G,reverse)
	def __len__(A):'Return the size of the sorted list.\n\n        ``sl.__len__()`` <==> ``len(sl)``\n\n        :return: size of sorted list\n\n        ';return A._len
	def bisect_left(A,value):
		'Return an index to insert `value` in the sorted list.\n\n        If the `value` is already present, the insertion point will be before\n        (to the left of) any existing values.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([10, 11, 12, 13, 14])\n        >>> sl.bisect_left(12)\n        2\n\n        :param value: insertion index of value in sorted list\n        :return: index\n\n        ';D=value;B=A._maxes
		if not B:return 0
		C=bisect_left(B,D)
		if C==len(B):return A._len
		E=bisect_left(A._lists[C],D);return A._loc(C,E)
	def bisect_right(A,value):
		'Return an index to insert `value` in the sorted list.\n\n        Similar to `bisect_left`, but if `value` is already present, the\n        insertion point will be after (to the right of) any existing values.\n\n        Similar to the `bisect` module in the standard library.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([10, 11, 12, 13, 14])\n        >>> sl.bisect_right(12)\n        3\n\n        :param value: insertion index of value in sorted list\n        :return: index\n\n        ';D=value;B=A._maxes
		if not B:return 0
		C=bisect_right(B,D)
		if C==len(B):return A._len
		E=bisect_right(A._lists[C],D);return A._loc(C,E)
	bisect=bisect_right;_bisect_right=bisect_right
	def count(A,value):
		'Return number of occurrences of `value` in the sorted list.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList([1, 2, 2, 3, 3, 3, 4, 4, 4, 4])\n        >>> sl.count(3)\n        3\n\n        :param value: value to count in sorted list\n        :return: count\n\n        ';D=value;B=A._maxes
		if not B:return 0
		C=bisect_left(B,D)
		if C==len(B):return 0
		G=A._lists;F=bisect_left(G[C],D);E=bisect_right(B,D)
		if E==len(B):return A._len-A._loc(C,F)
		H=bisect_right(G[E],D)
		if C==E:return H-F
		I=A._loc(E,H);J=A._loc(C,F);return I-J
	def copy(A):'Return a shallow copy of the sorted list.\n\n        Runtime complexity: `O(n)`\n\n        :return: new sorted list\n\n        ';return A.__class__(A)
	__copy__=copy
	def append(A,value):'Raise not-implemented error.\n\n        Implemented to override `MutableSequence.append` which provides an\n        erroneous default implementation.\n\n        :raises NotImplementedError: use ``sl.add(value)`` instead\n\n        ';raise NotImplementedError('use ``sl.add(value)`` instead')
	def extend(A,values):'Raise not-implemented error.\n\n        Implemented to override `MutableSequence.extend` which provides an\n        erroneous default implementation.\n\n        :raises NotImplementedError: use ``sl.update(values)`` instead\n\n        ';raise NotImplementedError('use ``sl.update(values)`` instead')
	def insert(A,index,value):'Raise not-implemented error.\n\n        :raises NotImplementedError: use ``sl.add(value)`` instead\n\n        ';raise NotImplementedError('use ``sl.add(value)`` instead')
	def pop(D,index=-1):
		"Remove and return value at `index` in sorted list.\n\n        Raise :exc:`IndexError` if the sorted list is empty or index is out of\n        range.\n\n        Negative indices are supported.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> sl.pop()\n        'e'\n        >>> sl.pop(2)\n        'c'\n        >>> sl\n        SortedList(['a', 'b', 'd'])\n\n        :param int index: index of value (default -1)\n        :return: value\n        :raises IndexError: if index is out of range\n\n        ";E=index
		if not D._len:raise IndexError('pop index out of range')
		A=D._lists
		if E==0:B=A[0][0];D._delete(0,0);return B
		if E==-1:C=len(A)-1;F=len(A[C])-1;B=A[C][F];D._delete(C,F);return B
		if 0<=E<len(A[0]):B=A[0][E];D._delete(0,E);return B
		G=len(A[-1])
		if-G<E<0:C=len(A)-1;F=G+E;B=A[C][F];D._delete(C,F);return B
		C,H=D._pos(E);B=A[C][H];D._delete(C,H);return B
	def index(E,value,start=None,stop=None):
		"Return first index of value in sorted list.\n\n        Raise ValueError if `value` is not present.\n\n        Index must be between `start` and `stop` for the `value` to be\n        considered present. The default value, None, for `start` and `stop`\n        indicate the beginning and end of the sorted list.\n\n        Negative indices are supported.\n\n        Runtime complexity: `O(log(n))` -- approximate.\n\n        >>> sl = SortedList('abcde')\n        >>> sl.index('d')\n        3\n        >>> sl.index('z')\n        Traceback (most recent call last):\n          ...\n        ValueError: 'z' is not in list\n\n        :param value: value in sorted list\n        :param int start: start index (default None, start of sorted list)\n        :param int stop: stop index (default None, end of sorted list)\n        :return: index of value\n        :raises ValueError: if value is not present\n\n        ";C=stop;B=value;A=start;D=E._len
		if not D:raise ValueError('{0!r} is not in list'.format(B))
		if A is None:A=0
		if A<0:A+=D
		if A<0:A=0
		if C is None:C=D
		if C<0:C+=D
		if C>D:C=D
		if C<=A:raise ValueError('{0!r} is not in list'.format(B))
		H=E._maxes;F=bisect_left(H,B)
		if F==len(H):raise ValueError('{0!r} is not in list'.format(B))
		I=E._lists;J=bisect_left(I[F],B)
		if I[F][J]!=B:raise ValueError('{0!r} is not in list'.format(B))
		C-=1;G=E._loc(F,J)
		if A<=G:
			if G<=C:return G
		else:
			K=E._bisect_right(B)-1
			if A<=K:return A
		raise ValueError('{0!r} is not in list'.format(B))
	def __add__(A,other):"Return new sorted list containing all values in both sequences.\n\n        ``sl.__add__(other)`` <==> ``sl + other``\n\n        Values in `other` do not need to be in sorted order.\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl1 = SortedList('bat')\n        >>> sl2 = SortedList('cat')\n        >>> sl1 + sl2\n        SortedList(['a', 'a', 'b', 'c', 't', 't'])\n\n        :param other: other iterable\n        :return: new sorted list\n\n        ";B=reduce(iadd,A._lists,[]);B.extend(other);return A.__class__(B)
	__radd__=__add__
	def __iadd__(A,other):"Update sorted list with values from `other`.\n\n        ``sl.__iadd__(other)`` <==> ``sl += other``\n\n        Values in `other` do not need to be in sorted order.\n\n        Runtime complexity: `O(k*log(n))` -- approximate.\n\n        >>> sl = SortedList('bat')\n        >>> sl += 'cat'\n        >>> sl\n        SortedList(['a', 'a', 'b', 'c', 't', 't'])\n\n        :param other: other iterable\n        :return: existing sorted list\n\n        ";A._update(other);return A
	def __mul__(A,num):"Return new sorted list with `num` shallow copies of values.\n\n        ``sl.__mul__(num)`` <==> ``sl * num``\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl = SortedList('abc')\n        >>> sl * 3\n        SortedList(['a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'])\n\n        :param int num: count of shallow copies\n        :return: new sorted list\n\n        ";B=reduce(iadd,A._lists,[])*num;return A.__class__(B)
	__rmul__=__mul__
	def __imul__(A,num):"Update the sorted list with `num` shallow copies of values.\n\n        ``sl.__imul__(num)`` <==> ``sl *= num``\n\n        Runtime complexity: `O(n*log(n))`\n\n        >>> sl = SortedList('abc')\n        >>> sl *= 3\n        >>> sl\n        SortedList(['a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'])\n\n        :param int num: count of shallow copies\n        :return: existing sorted list\n\n        ";B=reduce(iadd,A._lists,[])*num;A._clear();A._update(B);return A
	def __make_cmp(A,symbol,doc):
		'Make comparator method.'
		def B(self,other):
			'Compare method for sorted list and sequence.';B=other
			if not isinstance(B,Sequence):return NotImplemented
			C=self._len;D=len(B)
			if C!=D:
				if A is eq:return False
				if A is ne:return True
			for(E,F)in zip(self,B):
				if E!=F:return A(E,F)
			return A(C,D)
		C=A.__name__;B.__name__='__{0}__'.format(C);D='Return true if and only if sorted list is {0} `other`.\n\n        ``sl.__{1}__(other)`` <==> ``sl {2} other``\n\n        Comparisons use lexicographical order as with sequences.\n\n        Runtime complexity: `O(n)`\n\n        :param other: `other` sequence\n        :return: true if sorted list is {0} `other`\n\n        ';B.__doc__=dedent(D.format(doc,C,symbol));return B
	__eq__=__make_cmp(eq,'==','equal to');__ne__=__make_cmp(ne,'!=','not equal to');__lt__=__make_cmp(lt,'<','less than');__gt__=__make_cmp(gt,'>','greater than');__le__=__make_cmp(le,'<=','less than or equal to');__ge__=__make_cmp(ge,'>=','greater than or equal to');__make_cmp=staticmethod(__make_cmp)
	def __reduce__(A):B=reduce(iadd,A._lists,[]);return type(A),(B,)
	def __repr__(self):'Return string representation of sorted list.\n\n        ``sl.__repr__()`` <==> ``repr(sl)``\n\n        :return: string representation\n\n        ';return'{0}({1!r})'.format(type(self).__name__,list(self))
	def _check(A):
		'Check invariants of sorted list.\n\n        Runtime complexity: `O(n)`\n\n        '
		try:
			for D in A._lists:
				for B in range(1,len(D)):0
			for B in range(1,len(A._lists)):0
			for B in range(len(A._maxes)):0
			E=A._load<<1;F=A._load>>1
			for B in range(0,len(A._lists)-1):0
			if A._index:
				for B in range(len(A._lists)):G=A._index[A._offset+B]
				for B in range(A._offset):
					C=(B<<1)+1
					if C>=len(A._index):0
					elif C+1==len(A._index):0
					else:H=A._index[C]+A._index[C+1]
		except:traceback.print_exc(file=sys.stdout)

n, q = map(int, sys.stdin.readline().strip().split())
name2ind = dict()
for (i, name) in enumerate(sys.stdin.readline().strip().split()):
    name2ind[name] = i

scores = [0 for _ in range(n)]
rankings = SortedList(scores)

for _ in range(q):
    query = sys.stdin.readline().strip().split()
    if query[0] == "?":
        ind = name2ind[query[1]]
        score = scores[ind]
        print(rankings.bisect_left(score) + 1, score)
    else:
        for k in range(2, len(query), 2):
            ind = name2ind[query[k]]
            rankings.discard(scores[ind])
            scores[ind] += int(query[k + 1])
            rankings.add(scores[ind])
