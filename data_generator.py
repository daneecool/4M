"""
Simple Data Generator
Generates random numbers and saves them to data.txt in the same format as the original.
"""

import random

def generate_data():
    """Generate 400 random numbers between 10-100 and save to data.txt"""
    
    # Generate 400 random numbers between 10 and 100
    numbers = [random.randint(10, 100) for _ in range(400)]
    
    # Format as comma-separated values with 20 numbers per line (like original data.txt)
    lines = []
    for i in range(0, 400, 20):
        line = ','.join(str(num) for num in numbers[i:i+20]) + ','
        lines.append(line)
    
    # Write to data.txt
    with open('data.txt', 'w') as file:
        file.write('\n'.join(lines))
    
    print(f"Generated 400 random numbers and saved to data.txt")
    print(f"Sample: {numbers[:10]}")

def main():
    """Main function"""
    print("Data Generator for Statistics4M")
    print("-" * 30)
    generate_data()

if __name__ == "__main__":
    main()