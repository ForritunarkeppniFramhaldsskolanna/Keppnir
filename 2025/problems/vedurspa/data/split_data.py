#!/usr/bin/python3
from datetime import datetime
from pathlib import Path

FILENAMES = [
    "sj_gogn_2000_2004.txt",
    "sj_gogn_2005_2009.txt",
    "sj_gogn_2010_2014.txt",
    "sj_gogn_2015_2019.txt",
    "sj_gogn_2020_2024.txt",
]
STATION_METADATA_FILENAME = "stodva_upplysingar.txt"
NULLSTRING = "(null)"
NASTRING = "NA"
OUTPUT_DIR = "../stations/"


class Station:
    def __init__(
        self, id, name, kind, latitude_deg, longtitude_deg, latitude, longtitude, elevation, owner, start_year, end_year
    ):
        self.id = int(id) if id != NULLSTRING else None
        self.name = name if name != NULLSTRING else None
        self.kind = kind if kind != NULLSTRING else None
        self.latitude_deg = latitude_deg if latitude_deg != NULLSTRING else None
        self.longtitude_deg = longtitude_deg if longtitude_deg != NULLSTRING else None
        self.latitude = float(latitude) if latitude != NULLSTRING else None
        self.longtitude = float(longtitude) if longtitude != NULLSTRING else None
        self.elevation = float(elevation) if elevation != NULLSTRING else None
        self.owner = owner if owner != NULLSTRING else None
        self.start_year = int(start_year) if start_year != NULLSTRING else None
        self.end_year = int(end_year) if end_year != NULLSTRING else None

    def __repr__(self):
        return f"{self.__class__.__name__}({repr(self.id)}, {repr(self.name)}, {repr(self.kind)}, {repr(self.latitude_deg)}, {repr(self.longtitude_deg)}, {repr(self.latitude)}, {repr(self.longtitude)}, {repr(self.elevation)}, {repr(self.owner)}, {repr(self.start_year)}, {repr(self.end_year)})"


class DataPoint:
    def __init__(
        self, station_id, time, temperature, wind_direction, wind_force, wind_force_max, wind_gust, relative_humidity
    ):
        self.station_id = int(station_id) if station_id != NASTRING else None
        self.time = datetime.fromisoformat(time) if time != NASTRING else None
        self.temperature = float(temperature) if temperature != NASTRING else "-"
        self.wind_direction = int(wind_direction) if wind_direction != NASTRING else "-"
        self.wind_force = float(wind_force) if wind_force != NASTRING else "-"
        self.wind_force_max = float(wind_force_max) if wind_force_max != NASTRING else "-"
        self.wind_gust = float(wind_gust) if wind_gust != NASTRING else "-"
        self.relative_humidity = int(relative_humidity) if relative_humidity != "NA" else "-"

    def __str__(self):
        return f"{self.time} {self.temperature} {self.wind_direction} {self.wind_force} {self.relative_humidity}"


def load_station_metadata():
    stations = []
    with open(STATION_METADATA_FILENAME) as metadata_file:
        stations = [Station(*line.rstrip("\n").split("\t")) for line in metadata_file.readlines()[1:]]
    return stations


def load_station_data(stations):
    data = {station.id: [] for station in stations}
    for filename in FILENAMES:
        with open(filename) as file:
            for line in file.readlines()[1:]:
                dp = DataPoint(*(x.strip() for x in line.split("\t")))
                if dp.station_id not in data:
                    data[dp.station_id] = []
                data[dp.station_id].append(dp)
    return data


stations = load_station_metadata()
station_map = {station.id: station for station in stations}
data = load_station_data(stations)

output_dir = Path(OUTPUT_DIR)
output_dir.mkdir(exist_ok=True)
for id, data_points in data.items():
    if id not in station_map or len(data_points) == 0:
        continue
    file_path = output_dir / f"{id}.txt"
    with open(file_path, "w") as f:
        f.write(f"{len(data_points)}\n")
        f.write(f"{station_map[id].latitude} {station_map[id].longtitude} {station_map[id].elevation}\n")
        for dp in data_points:
            f.write(f"{dp}\n")
