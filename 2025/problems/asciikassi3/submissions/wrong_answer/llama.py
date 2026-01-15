class Box:
    def __init__(self, h, w, d):
        self.h = h
        self.w = w
        self.d = d

    def draw_face(self, x, y, z, face):
        if z == 1 and face != "top":
            return ""
        elif z > 2:
            res = []
            for i in range(x + 2, x + self.w - 2):
                res.append(" " * (x + 1 + i - x) + "+")
                for j in range(self.h - 2):
                    if j != self.h // 2 and i == x + 3:
                        res[-1] = "+" + res[-1][1:]
                    else:
                        res[-1] += "-"
                res.append("+")

            return "\n".join(res)
        elif z == 1 or face == "top":
            if face == "front":
                res = []
                for i in range(y):
                    res.append(" " * x + "+")
                    for j in range(self.w - 2):
                        res[-1] += "-"
                    res[-1] += "+"
                return "\n".join(res)
            elif face == "back":
                res = []
                for i in range(y):
                    res.append(" " * x + "-")
                    for j in range(self.w - 2):
                        if y != self.w // 2:
                            res[-1] += "-"
                        else:
                            res[-1] += "+"
                    res[-1] += "-"
                return "\n".join(res)
        elif z > 2 and face == "front":
            res = []
            for i in range(y + 3, y + self.w - 2):
                res.append(" " * (y + 1 + i - y) + "+")
                for j in range(self.h - 2):
                    if j != self.h // 2 and i == y + 4:
                        res[-1] = "+" + res[-1][1:]
                    else:
                        res[-1] += "-"
                res.append("+")

            return "\n".join(res)
        elif z > 2 and face == "back":
            res = []
            for i in range(y + 3, y + self.w - 2):
                res.append(" " * (y + 1 + i - y) + "+")
                for j in range(self.h - 2):
                    if j != self.h // 2 and i == y + 4:
                        res[-1] = "+" + res[-1][1:]
                    else:
                        res[-1] += "-"
                res.append("+")

            return "\n".join(res)

    def draw_box(self):
        res = []
        for z in range(3):
            if self.d == 2 or (self.h > 2 and self.w > 2):
                for y in range(max(0, self.w - self.h), min(self.w, self.h)):
                    res.append(self.draw_face(1 + y - self.h // 2, 1, z, "front") if self.d == 2 else "")
            elif self.d == 1 and (self.h > 2 or self.w > 2):
                for i in range(self.h):
                    res.append(
                        " " * max(0, self.w - self.h)
                        + ("-" if self.w > 3 else "+")
                        + "-" * (max(0, self.w - 3) if self.w > 3 else 0)
                    )
            elif z == 1:
                for y in range(max(0, self.w - self.h), min(self.w, self.h)):
                    res.append(self.draw_face(1 + y - self.h // 2, 1, z, "front") if self.d == 1 else "")
                return "\n".join(res)
            elif self.d > 2:
                for i in range(max(0, self.w - self.h), min(self.w, self.h)):
                    res.append(" " * (max(0, self.w - self.h) + max(0, self.h - self.w)) + "/")
        return "\n".join(res)


h, w, d = map(int, input().split())
print(Box(h, w, d).draw_box())
