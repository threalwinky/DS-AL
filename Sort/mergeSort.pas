
uses crt;
var a, tmp:array[0..100] of Integer;
	sl, dem : Integer;
procedure mergesort(l: Integer; r : Integer);
var m, i, j, k : Integer;
begin
	if l < r then
	
	begin
		
		m := (l + r) div 2;
		mergesort(l, m);
		mergesort(m + 1, r);
		i := l; j:= m + 1;k:= 0;
		while ((i <= m) or (j <= r)) do
		begin
			if (((i <= m) and (j <= r) and (a[i] < a[j])) or (j > r)) then
			begin
				tmp[k] := a[i];
				k := k+1;
				i := i+1;
			end
			else
			begin
				tmp[k] := a[j];
				k := k+1;
				j:=j+1;
			end;
		end;
		for dem := 0 to k - 1 do a[l + dem] := tmp[dem];
	end;
end;
begin
	clrscr;
	sl := 100;
	randomize;
	for dem := 0 to sl do a[dem] := random(100);
	for dem := 0 to sl do write(a[dem], ' ');
	writeln;

	mergesort(0, sl);

	for dem := 0 to sl do write(a[dem], ' ');
end.