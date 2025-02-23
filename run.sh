clear

if [ ! -d "./exe" ]; then
    mkdir exe
fi

code_name="tmp"
# gcc $code_name.cpp -o exe/$code_name -O2 --std=c++20 -Wall
c++ $code_name.cpp -o exe/$code_name -O2 --std=c++20

for input_file in input/*; do
    if [ -f "$input_file" ]; then
        filename=$(basename "$input_file")
        output_file="output/${filename%.in}.out"
        exe/$code_name < "$input_file" | tee "$output_file"
    fi
done

# exe/$code_name
