function m = highlight_center_of_image(m)

    [row, column] = size(m);

    for c = uint8(row/2 - 50): uint8(row/2 + 50) 
        for r = uint8(column/2 - 50): uint8(column/2 + 50) 
            m(r,c) = 255;
        end
    end
end