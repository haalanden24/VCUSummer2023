#!/usr/bin/env python3

#Evan Haaland xmlread.py

import xml.etree.ElementTree as ET
import json

def xml_to_dict(element):
    result = {}
    
    result.update(element.attrib)

    # Process the sub-elements (children) of the current element
    for sub_element in element:
        sub_element_dict = xml_to_dict(sub_element)
        if sub_element.tag in result:
            # If the tag name already exists in the dictionary, convert it into a list of dictionaries
            if not isinstance(result[sub_element.tag], list):
                result[sub_element.tag] = [result[sub_element.tag]]
            result[sub_element.tag].append(sub_element_dict)
        else:
            result[sub_element.tag] = sub_element_dict

   
    
    if element.text:
        if element.tag == "Int32":

            result['Int32'] = element.text.strip()
        elif element.tag == "Boolean":
            result['Boolean'] = element.text.strip()
        
        elif element.tag == "String":
            result['String'] = element.text.strip()

    return result
    
objmlfile = "InputData.objml" #name of input file

#sets the parser to parse through xmlfile (objml in ourcase)
tree = ET.parse(objmlfile) 
root = tree.getroot()

#runs the function we made to get elements from program
xml_data_dict = xml_to_dict(root)

#converts everything to json format
json_string = json.dumps(xml_data_dict, indent=4)

#writes it into a .txt file named data.json
with open("data.json", "w") as file:
    file.write(json_string)
