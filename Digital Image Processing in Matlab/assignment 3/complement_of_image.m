function m = complement_of_image(A)

[row, column] = size(A);

for r = 1:row
    for c = 1:column
        m(r,c) = 1 - A(r,c);
    end
end

end