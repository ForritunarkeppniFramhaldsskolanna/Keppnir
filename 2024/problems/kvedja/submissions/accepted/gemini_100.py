#!/usr/bin/python3
def generate_signature(sender_name):
    """Generates a simple email signature."""
    return f"Kvedja,\n{sender_name}"


# Get the sender's name
sender_name = input()

# Generate the signature
signature = generate_signature(sender_name)

# Print the signature (Mirko would integrate this into his email client)
print(signature)
