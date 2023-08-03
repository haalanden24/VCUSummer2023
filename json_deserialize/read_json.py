import json

def read_json_file(file_path):
    try:
        with open(file_path, 'r') as json_file:
            data = json.load(json_file)
            return data
    except FileNotFoundError:
        print(f"Error: File not found at '{file_path}'")
        return None
    except json.JSONDecodeError:
        print(f"Error: Invalid JSON format in '{file_path}'")
        return None
    except Exception as e:
        print(f"Error: {e}")
        return None

# Replace 'path/to/your/data.json' with the actual path to your JSON file
file_path = 'C:\\Users\\evanh\\OneDrive\\Desktop\\VCU_Spring_2023\\VIP\\example_json_data\\basic_example.json'
json_data = read_json_file(file_path)

if json_data:
    print(json_data)





