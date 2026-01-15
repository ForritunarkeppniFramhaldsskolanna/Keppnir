class Segment:
    def __init__(self, p, q):
        self.p = p
        self.q = q

    def __iter__(self):
        return iter((self.p, self.q))

    def __eq__(self, other):
        return self.p == other.p and self.q == other.q

    def intersect(self, other):
        r = self.q - self.p
        s = other.q - other.p
        c = r.cross(s)
        d = other.p - self.p
        if c == 0:
            if abs(d.cross(r)) > 0:
                return None
            numer1 = d.dot(r)
            numer2 = numer1 + s.dot(r)
            denom = r.dot(r)
            if numer2 < numer1:
                numer1, numer2 = numer2, numer1
            start = max(0, numer1)
            end = min(denom, numer2)
            if start == end:
                return self.p + r * (start / denom)
            if start > end:
                return None
            return Segment(self.p + r * (start / denom), self.p + r * (end / denom))

        t_numer = d.cross(s)
        t_denom = r.cross(s)
        is_t_in_range = min(0, t_denom) <= t_numer <= max(0, t_denom)

        u_numer = (self.p - other.p).cross(r)
        u_denom = s.cross(r)
        is_u_in_range = min(0, u_denom) <= u_numer <= max(0, u_denom)

        if is_t_in_range and is_u_in_range:
            return self.p + r * (t_numer / t_denom)
        return None

    def __str__(self):
        return f"{self.p} -- {self.q}"

    def __repr__(self):
        return f"Segment({repr(self.p)},{repr(self.q)})"

    def __hash__(self):
        return hash(tuple(self))
