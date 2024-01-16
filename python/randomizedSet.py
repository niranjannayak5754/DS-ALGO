import random

class RandomizedSet:

    def __init__(self):
        self.values = [] # list of values
        self.values_to_indices = {} # dict storing values and their indices

    def insert(self, val: int) -> bool:
        if val not in self.values:
            self.values.append(val)
            self.values_to_indices[val] = len(self.values) - 1
            return True
        
        return False

    def remove(self, val: int) -> bool:
        if val in self.values:
            idx = self.values_to_indices[val]
            last_val = self.values[-1]
            # replace curr idx with last_val and update the dict
            self.values[idx] = last_val
            self.values_to_indices[last_val] = idx
            # delete the curr val from dict and list both
            del self.values_to_indices[val]
            self.values.pop()
            return True

        return False

    def getRandom(self) -> int:
        return random.choice(self.values)
        


# Your RandomizedSet object will be instantiated and called as such:
obj = RandomizedSet()
obj.insert(5)
obj.insert(7)

print(obj.getRandom())
obj.insert(12)
obj.remove(6)
print(obj.getRandom())
obj.remove(12)
print(obj.getRandom())
obj.insert(66)
obj.remove(5)

print(obj.getRandom())
print(obj.getRandom())