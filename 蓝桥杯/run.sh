clear
code_name="P8740"
g++ $code_name.cpp -o exe/$code_name 

for input_file in input/*; do
    if [ -f "$input_file" ]; then
        filename=$(basename "$input_file")
        output_file="output/${filename%.in}.out"
        exe/$code_name < "$input_file" | tee "$output_file"
    fi
done
