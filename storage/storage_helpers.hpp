#pragma once

#include "geometry/point2d.hpp"
#include "geometry/rect2d.hpp"

#include "platform/country_defines.hpp"

#include "storage/storage_defines.hpp"

namespace storage
{
class CountryInfoGetter;
class Storage;

/// \returns true if |position| is covered by a downloaded mwms and false otherwise.
/// \note |position| has coordinates in mercator.
/// \note This method takes into acount only maps enumerated in countries.txt.
bool IsPointCoveredByDownloadedMaps(m2::PointD const & position, Storage const & storage,
                                    CountryInfoGetter const & countryInfoGetter);

bool IsDownloadFailed(Status status);

bool IsEnoughSpaceForDownload(MwmSize mwmSize);
bool IsEnoughSpaceForDownload(MwmSize mwmSizeDiff, MwmSize maxMwmSize);
bool IsEnoughSpaceForDownload(CountryId const & countryId, Storage const & storage);
bool IsEnoughSpaceForUpdate(CountryId const & countryId, Storage const & storage);

/// \brief Calculates limit rect for |countryId| (expandable or not).
/// \returns bounding box in mercator coordinates.
m2::RectD CalcLimitRect(CountryId const & countryId, Storage const & storage,
                        CountryInfoGetter const & countryInfoGetter);
}  // namespace storage
