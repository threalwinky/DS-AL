uses crt;
var a:array[1..100] of Integer;
    n,m,i:integer;
    check:boolean;
procedure inp;
begin
     read(n);
     readln(m
     );
     for i:=1 to n-1 do
           read(a[i]);
     readln(a[n]);
end;
procedure lin;
begin
     for i:=1 to n do
         begin
              if (a[i] = m) then
                 check:=true;
         end;
end;
procedure out;
begin
     if check = true then writeln('FOUND')
     else writeln('NOT FOUND');
     readln;
end;
begin
     clrscr;
     inp;
     lin;
     out;

end.