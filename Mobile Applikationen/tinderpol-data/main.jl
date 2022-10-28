import Pkg
import JSON
Pkg.add("HTTP")
import HTTP

url = "https://restcountries.com/v3.1/all"
r = HTTP.get(url)
d = JSON.parse(String(r.body))
map!(x -> x["cca2"], d, d)

notices = []

function req(keyArgs...)
	url = "https://ws-public.interpol.int/notices/v1/red"
	keyArgs = map(x -> string(x[1]) * "=" * string(x[2]), keyArgs)
	url *= "?" * join(keyArgs, "&")
	d = JSON.parse(String(HTTP.get(url).body))
	if d["total"] != length(d["_embedded"]["notices"])
		println("$(url):  total=$(d["total"])  notices=$(length(d["_embedded"]["notices"]))")
	end
	return d
end

age_args = [(0, 18)]
for i in range(19, 60)
	push!(age_args, (i, i))
end
push!(age_args, (60, 120))

for cc in d
	country_arg = ("nationality", cc)
	resPerPage_arg = ("resultPerPage", 200)
	resp = req(country_arg, resPerPage_arg)
	country_notices = resp["_embedded"]["notices"]
	if length(country_notices) < resp["total"]
		country_notices = []
		sexIds = ["F", "M", "U"]
		for id in sexIds
			sd = req(country_arg, resPerPage_arg, ("sexId", id))
			if sd["total"] > length(sd["_embedded"]["notices"])
				for age_arg in age_args
					asd = req(country_arg, resPerPage_arg, ("ageMin", age_arg[1]), ("ageMax", age_arg[2]))
					push!(country_notices, asd["_embedded"]["notices"]...)
				end
			else
				push!(country_notices, sd["_embedded"]["notices"]...)
			end
		end
	end
	# println("$(cc): $(length(country_notices))")
	push!(notices, country_notices...)
end

length(notices)

sort!(notices, by = x -> x["entity_id"]);

i = 1
while (i + 1 < length(notices))
	if notices[i]["entity_id"] == notices[i+1]["entity_id"]
		deleteat!(notices, i+1)
	else
		i += 1
	end
end

open("data.json", "w") do f
	write(f, JSON.json(notices, 4))
end