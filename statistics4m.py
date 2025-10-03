"""
Statistics4M Module
A class for calculating basic statistical measures: Mode, Mean, Median, and Maximum
"""

import statistics

class Statistics4M:
    """A class to calculate basic statistical measures for a dataset."""
    
    def __init__(self, data):
        """Initialize with a list of numeric data."""
        self.data = sorted(data)  # sort for easier median calculation

    def mean(self):
        """Calculate the arithmetic mean of the data."""
        return sum(self.data) / len(self.data)

    def median(self):
        """Calculate the median of the data."""
        n = len(self.data)
        mid = n // 2
        if n % 2 == 0:  # even number of elements
            return (self.data[mid - 1] + self.data[mid]) / 2
        else:  # odd number of elements
            return self.data[mid]

    def mode(self):
        """Calculate the mode of the data using Python's built-in mode function."""
        return statistics.mode(self.data)

    def maximum(self):
        """Find the maximum value in the data."""
        return max(self.data)

    def summary(self):
        """Return a dictionary with all statistical measures."""
        return {
            "Mean": self.mean(),
            "Median": self.median(),
            "Mode": self.mode(),
            "Max": self.maximum()
        }

def read_data_from_file(filename):
    """Read numeric data from a text file containing comma-separated values."""
    with open(filename, 'r') as file:
        # Read the entire file, remove whitespace, and split by commas
        content = file.read().strip().replace('\n', '').replace(' ', '')
        # Convert to list of integers
        data = [int(x) for x in content.split(',') if x]
    return data