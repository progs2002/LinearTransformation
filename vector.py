class Vector:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    
    def __repr__(self):
        return(str(self.x)+'i '+str(self.y)+'j')

    def dotProduct(Vector v1, Vector v2):
        return