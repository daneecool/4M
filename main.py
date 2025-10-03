"""
Main execution file for Statistics4M
This file imports the Statistics4M class and demonstrates its usage with data from a file.
"""

from statistics4m import Statistics4M, read_data_from_file

def main():
    """Main function to execute the statistical analysis."""
    
    # Read data from file instead of using hardcoded numbers
    try:
        numbers = read_data_from_file(r'C:\Users\daniel-goh\data.txt')
        print(f"Successfully loaded {len(numbers)} data points from file")
        
        stats = Statistics4M(numbers)
        
        print("\nStatistics for imported data:")
        print("Mean   :", round(stats.mean(), 2))
        print("Median :", stats.median())
        print("Mode   :", stats.mode())
        print("Max    :", stats.maximum())
        
        print("\nSummary:", stats.summary())
        
    except FileNotFoundError:
        print("Error: data.txt file not found. Using default numbers.")
        # Fallback to original example
        numbers = [4, 1, 2, 2, 3, 5, 4, 2]
        stats = Statistics4M(numbers)
        
        print("Mean   :", stats.mean())
        print("Median :", stats.median())
        print("Mode   :", stats.mode())
        print("Max    :", stats.maximum())
        
        print("\nSummary:", stats.summary())

if __name__ == "__main__":
    main()