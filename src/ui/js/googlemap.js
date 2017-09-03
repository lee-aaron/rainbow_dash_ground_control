
function initMap() {
  var ucsd = {lat: 32.8812, lng: -117.2374};
  var map = new google.maps.Map(document.getElementById('GPS'), {
    zoom: 17,
    center: ucsd,
    mapTypeId: 'terrain'
  });
  var elevator = new google.maps.ElevationService;
  var infowindow = new google.maps.InfoWindow({map: map});

  map.addListener('click', function(event) {
    displayLocationElevation(event.latLng, elevator, infowindow);
  });

  var marker = new google.maps.Marker({
    position: ucsd,
    map: map
  });
}

function displayLocationElevation(location, elevator, infowindow) {
  // Initiate the location request
  elevator.getElevationForLocations({
    'locations': [location]
  }, function(results, status) {
    infowindow.setPosition(location);
    if (status === 'OK') {
      // Retrieve the first result
      if (results[0]) {
        // Open the infowindow indicating the elevation at the clicked position.
        infowindow.setContent('The elevation at this point <br>is ' +
            results[0].elevation + ' meters.');
      } else {
        infowindow.setContent('No results found');
      }
    } else {
      infowindow.setContent('Elevation service failed due to: ' + status);
    }
  });
}
