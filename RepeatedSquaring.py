# Repeated Squaring

def exp(base, i):
    if i == 0:
        return 1
    
    # If i is Even
    if i % 2 == 0:
        alpha = exp(base, i / 2)
        return alpha * alpha
    
    # If i is Odd
    alpha = exp(base, (i - 1) / 2)
    return alpha * alpha * base
    
print(exp(2, 1000))