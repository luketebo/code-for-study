class Circle:
    _radius = 0
    def __init__(self, radius):
        self._radius = radius
    def get_perimeter(self):
        print(f"周长:{2 * 3.14 * self._radius}")
    def get_area(self):
        print(f"面积:{3.14 * self._radius ** 2}")
        
test = Circle(5)
test.get_area()
test.get_perimeter()