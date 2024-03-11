#!/bin/bash

# Find all C files recursively in subdirectories
find . -name '*.c' | while read file; do
    if [ -f "$file" ]; then
        filename=$(basename "$file" .c)
        output_path=$(dirname "$file")
        clang -o "${output_path}/${filename}" "$file"
        clang -o "${output_path}/${filename}.exe" "$file"
        if [ $? -eq 0 ]; then
            echo "Compilation successful for $file"
        else
            echo "Error compiling $file"
            exit 1 # Exit the pipeline with a non-zero status code
        fi
    fi
done
 39 changes: 39 additions & 0 deletions39  
rename.sh
Viewed
@@ -0,0 +1,39 @@
#!/bin/bash

rename_files_recursively() {
    find . -type f -name '*.cpp' | while read -r file; do
        relative_path=$(dirname "$file")
        newname="$relative_path/$(basename "$file" .cpp).c"
        mv "$file" "$newname"
        echo "Renamed: $file to $newname"
    done
}

remove_polish_characters() {
    find . -depth -name '*[ąćęłńóśźżĄĆĘŁŃÓŚŹŻ]*' | while read -r file; do
        newname=$(echo "$file" | iconv -f UTF-8 -t ASCII//TRANSLIT | sed 'y/ąćęłńóśźżĄĆĘŁŃÓŚŹŻ/acelnoszzACELNOSZZ/')
        mv "$file" "$newname"
        echo "Renamed: $file to $newname"
    done
}

replace_space_with_underscore_in_directories() {
    find . -depth -type d -name '* *' | while read -r directory; do
        newname=$(echo "$directory" | tr ' ' '_')
        mv "$directory" "$newname"
        echo "Renamed directory: $directory to $newname"
    done
}

replace_space_with_underscore_in_files() {
    find . -depth -type f -name '* *' | while read -r file; do
        newname=$(echo "$file" | tr ' ' '_')
        mv "$file" "$newname"
        echo "Renamed file: $file to $newname"
    done
}


# Znajdź wszystkie pliki z rozszerzeniem .c w bieżącym katalogu i podkatalogach
replace_scanf_s_to_scanf(){find . -type f -name "*.c" -print0 | while IFS= read -r -d $'\0' file; do
    # Użyj sed do zamiany wszystkich wystąpień scanf_s na scanf w znalezionym pliku
    sed -i 's/scanf_s/scanf/g' "$file"
done
}
replace_scanf_s_to_scanf
rename_files_recursively
remove_polish_characters
replace_space_with_underscore_in_directories
replace_space_with_underscore_in_files