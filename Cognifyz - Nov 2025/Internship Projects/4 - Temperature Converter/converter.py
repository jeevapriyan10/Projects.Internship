def main():
    while True:
        print("=====Temperature Converter=====")
        print("Units : Celsius, Fahrenheit, Kelvin")
        print("Enter The Unit to Convert From (To quit - Type [exit]): ")

        from_unit = input().strip().lower()
        if from_unit == "exit":
            print("Exiting the Temperature Converter!")
            return
        
        print("Enter The Unit to Convert To (To quit - Type [exit]): ")
        to_unit = input().strip().lower()
        if to_unit == "exit":
            print("Exiting the Temperature Converter!")
            return
        
        print("Enter The Temperature Value : ")
        temp = float(input())

        if from_unit not in ["celsius", "fahrenheit", "kelvin"] or to_unit not in ["celsius", "fahrenheit", "kelvin"]:
            print("Invalid unit entered. Please try again.")
            continue
        if from_unit == to_unit:
            print(f"The converted temperature is: {temp} {to_unit.capitalize()}")
            continue

        if from_unit == "celsius":
            if to_unit == "fahrenheit":
                converted_temp = (temp * 9/5) + 32
            elif to_unit == "kelvin":
                converted_temp = temp + 273.15  
        elif from_unit == "fahrenheit":
            if to_unit == "celsius":
                converted_temp = (temp - 32) * 5/9
            elif to_unit == "kelvin":
                converted_temp = (temp - 32) * 5/9 + 273.15
        elif from_unit == "kelvin":
            if to_unit == "celsius":
                converted_temp = temp - 273.15
            elif to_unit == "fahrenheit":
                converted_temp = (temp - 273.15) * 9/5 + 32
        
        print(f"The converted temperature is: {converted_temp:.2f} {to_unit.capitalize()}")

if __name__ == "__main__":
    main() 