
#ifndef HTML_MACROS_H_
#define HTML_MACROS_H_

#if USE_HTML_FROM_MACROS

/* START HTML MACROS AREA */

/*
 * Automatically generated macros by 'HTML-Minify-and-Macro-Converter v2.0'
 * containing the HTML code converted to macros.
 * The parameters are:
 *    Output: main/html_macros.h
 *    Input[1]: html/index.html, Macro: INDEX_HTML
 *    Input[2]: html/mesh_graph.html, Macro: MESH_GRAPH_HTML
 *
 * Project Repository: https://github.com/moschiel/html-minify-and-macro-converter
 */

#define INDEX_HTML "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /><style>body { font-family: Arial, sans-serif; margin: auto; padding: 20px; justify-content: center; align-items: center; background-color: #f0f0f0; display: flex; flex-direction: column; } .container { width: 100%; max-width: 400px; background-color: #fff; padding: 20px; box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1); border-radius: 8px; text-align: left; } input[type='text'], input[type='password'] { width: 80%; padding: 10px; margin: 10px 0px; border: 1px solid #ccc; border-radius: 4px; font-size: 16px; } button, input[type='submit'] { background-color: #4CAF50; color: white; padding: 10px 20px; border: none; border-radius: 4px; cursor: pointer; font-size: 16px; } button:hover, input[type='submit']:hover { background-color: #45a049; } table { border-collapse: collapse; width: 100%; } table, th, td { border:1px solid black; }</style><script>let ws;function formatMeshID(e){var r = e.target.value.replace(/[^a-fA-F0-9]/g,'');e.target.value = r.match(/.{1,2}/g).join('-');}function togglePassword(id){var x = document.getElementById(id);if (x.type === 'password'){x.type = 'text';}else{x.type = 'password';}}function fetchJsonConfigs(){fetch('/get_configs') .then(response => response.json()) .then(data => applyConfigs(data)) .catch(error => console.error('Error fetching data:',error));}function applyConfigs(data){document.getElementById('device_mac_addr').value = data.device_mac_addr;document.getElementById('router_ssid').value = data.router_ssid;document.getElementById('router_password').value = data.router_password;document.getElementById('mesh_id').value = data.mesh_id;document.getElementById('mesh_password').value = data.mesh_password;document.getElementById('firmware_url').value = data.fw_url;}function fetchJsonMeshList(){fetch('/mesh_list_data') .then(response => response.json()) .then(data => buildMeshTable(data)) .catch(error => console.error('Error fetching data:',error));}function buildMeshTable(data){let table = document.getElementById('meshTable');table.innerHTML = '<tr><th>Node</th><th>Parent</th><th>Layer</th></tr>';if(data.nodes){data.nodes.forEach(node =>{let row = table.insertRow();row.insertCell(0).textContent = node.name;row.insertCell(1).textContent = node.parent;row.insertCell(2).textContent = node.layer;});}}function sendFirmwareURL(){if(ws != null && ws.readyState === WebSocket.OPEN) return;const url = document.getElementById('firmware_url').value;const ota_status = document.getElementById('ota_status');ws = new WebSocket('ws://' + window.location.host + '/ws_update');ws.onopen = function(){ws.send(JSON.stringify({fw_url:url}));};ws.onmessage = function(event){const data = JSON.parse(event.data);if (data.msg){ota_status.textContent = data.msg;}if (data.done){ws.close();}};ws.onerror = function(error){console.error('WebSocket Error: ',error);ota_status.textContent = 'Update Failed!';};ws.onclose = function(){console.log('WebSocket Closed');ota_status.textContent = 'WebSocket Closed';};}function submitConfigForm(event){event.preventDefault();const formData = new FormData(event.target);const params = new URLSearchParams();for (const pair of formData.entries()){params.append(pair[0],pair[1]);}const statusConfig = document.getElementById('status_config');statusConfig.textContent = 'Command sent';fetch('/set_wifi',{method:'POST',body:params.toString(),headers:{'Content-Type':'application/x-www-form-urlencoded'}}) .then(response =>{if (response.ok){statusConfig.textContent = 'WiFi settings updated, Restarting...';}else{statusConfig.textContent = 'Error setting configs';}}) .catch(error =>{statusConfig.textContent = 'Error sending configs';console.error('Error:',error);});}document.addEventListener('DOMContentLoaded',fetchJsonConfigs);document.addEventListener('DOMContentLoaded',fetchJsonMeshList);</script></head><body><br /><p>v1.6</p><div class=\"container\"><h2>Device Info</h2><p >Root MAC address:<span id=\"device_mac_addr\">08:d1:f9:dd:80:9c</span></p></div><br /><div class=\"container\"><form onsubmit=\"submitConfigForm(event)\"><h2>Configure WiFi Router</h2><label for=\"router_ssid\">Router SSID:</label><br /><input type=\"text\" id=\"router_ssid\" name=\"router_ssid\" required /><br /><label for=\"router_password\">Router Password:</label><br /><input type=\"password\" id=\"router_password\" name=\"router_password\" required /><br /><input type=\"checkbox\" onclick='togglePassword(\"router_password\")' />Show Password<br /><br /><br /><h2>Configure Mesh Network</h2><label for=\"mesh_id\">Mesh ID:</label><br /><input type=\"text\" id=\"mesh_id\" name=\"mesh_id\" required oninput=\"formatMeshID(event)\" maxlength=\"17\" /><br /><label for=\"mesh_password\">Mesh Password:</label><br /><input type=\"password\" id=\"mesh_password\" name=\"mesh_password\" required /><br /><input type=\"checkbox\" onclick='togglePassword(\"mesh_password\")' />Show Password<br /><br /><input type=\"submit\" value=\"Update Config\" /><p id=\"status_config\"></p></form></div><br /><div class=\"container\"><h2>Update Firmware</h2><label for=\"firmware_url\">Firmware URL:</label><br /><input type=\"text\" id=\"firmware_url\" name=\"firmware_url\" required /><br /><button onclick=\"sendFirmwareURL()\">Update Firmware</button><p id=\"ota_status\">Update Status: Not Started</p></div><br /><div class=\"container\"><h3>Nodes in Mesh Network</h3><button onclick=\"openTree()\">Open Tree View</button><button onclick=\"fetchJsonMeshList()\">Refresh</button><br /><br /><table id=\"meshTable\"></table></div><script>function openTree(){window.open('mesh_tree_view','_blank');}</script></body></html>"

#define MESH_GRAPH_HTML "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Mesh Network Tree</title><style>html { height: 100%; } body { font-family: Arial, sans-serif; margin: auto; padding: 10px; background-color: #f4f4f4; height: 100%; } h1 { color: #333; text-align: center; } button { background-color: #4CAF50; color: white; padding: 10px 20px; border: none; border-radius: 4px; cursor: pointer; font-size: 16px; } button:hover { background-color: #45a049; } .container { width: 100%; max-width: 1600px; margin: 0 auto; height: 100%; display: flex; flex-direction: column; } .svg-container { width: 100%; height: 100%; border: 1px solid #ddd; border-radius: 4px; background-color: #fff; position: relative; } svg { width: 100%; height: 100%; } .node { cursor: pointer; } .node rect { stroke: steelblue; stroke-width: 3px; rx: 10; ry: 10; } .node text { font: 12px sans-serif; font-weight: bold; } .link { fill: none; stroke: #666; } @media (max-width: 600px) { .node rect { stroke-width: 6px; width: 220px; height: 60px; x: -110px; y: -40px; } .node text { font: 40px sans-serif; font-weight: bold; } .link { stroke-width: 4px; } } @media (min-width: 601px) { .node rect { stroke-width: 3px; width: 120px; height: 30px; x: -60px; y: -20px; } .node text { font: 18px sans-serif; font-weight: bold; } .link { stroke-width: 2px; } }</style></head><body><div class=\"container\"><p>v1.2</p><h1>Mesh Network Tree</h1><button id=\"load-button\" onclick=\"fetchTreeData()\">Refresh</button><div class=\"svg-container\"><svg viewBox=\"0 0 960 800\" preserveAspectRatio=\"xMidYMid meet\"><g class=\"zoomable\"></g></svg></div></div><script src=\"https://d3js.org/d3.v6.min.js\"></script><script>const svg = d3.select(\"svg\");const width = +svg.attr(\"viewBox\").split(\" \")[2];const height = +svg.attr(\"viewBox\").split(\" \")[3];const zoomable = svg.select(\".zoomable\");const zoom = d3.zoom() .scaleExtent([0.1,10]) .on(\"zoom\",(event) =>{zoomable.attr(\"transform\",event.transform);});svg.call(zoom);const g = zoomable.append(\"g\").attr(\"transform\",\"translate(40,40)\");const tree = d3.tree().size([height,width - 160]);let i = 0;function collapse(d){if (d.children){d._children = d.children;d._children.forEach(collapse);d.children = null;}}function expand(d){if (d._children){d.children = d._children;d.children.forEach(expand);d._children = null;}}function getColor(layer){switch (layer){case 0:return '#ffcccc';case 1:return '#ffebcc';case 2:return '#ffffcc';case 3:return '#ccffcc';case 4:return '#cceeff';case 5:return '#ccccff';default:return '#fff';}}function getClass(layer){switch (layer){default:return 'node';}}function update(source,root){const treeData = tree(root);const nodes = treeData.descendants();const links = treeData.descendants().slice(1);nodes.forEach(d =>{d.y = d.depth * 180;});const node = g.selectAll('g.node').data(nodes,d => d.id || (d.id = ++i));const nodeEnter = node.enter().append('g').attr('class',d => getClass(d.data.layer)).attr('transform',d => `translate(${source.x0},${source.y0})`).on('click',(event,d) =>{if (d.children){d._children = d.children;d.children = null;}else{d.children = d._children;d._children = null;}update(d,root);});nodeEnter.append('rect') .attr('fill',d => getColor(d.data.layer)) .attr('class',d => getClass(d.data.layer));nodeEnter.append('text').style('text-anchor','middle').text(d => d.data.name);const nodeUpdate = nodeEnter.merge(node);nodeUpdate.transition().duration(750).attr('transform',d => `translate(${d.x},${d.y})`);nodeUpdate.select('rect') .attr('fill',d => getColor(d.data.layer)) .attr('class',d => getClass(d.data.layer));const nodeExit = node.exit().transition().duration(750).attr('transform',d => `translate(${source.x},${source.y})`).remove();const link = g.selectAll('path.link').data(links,d => d.id);const linkEnter = link.enter().insert('path','g').attr('class','link').attr('d',d =>{const o ={x:source.x0,y:source.y0};return diagonal(o,o);});linkEnter.transition().duration(750).attr('d',d => diagonal(d,d.parent));link.transition().duration(750).attr('d',d => diagonal(d,d.parent));link.exit().transition().duration(750).attr('d',d =>{const o ={x:source.x,y:source.y};return diagonal(o,o);}).remove();nodes.forEach(d =>{d.x0 = d.x;d.y0 = d.y;});function diagonal(s,d){return `M${s.x},${s.y}C${s.x},${(s.y + d.y) / 2}${d.x},${(s.y + d.y) / 2}${d.x},${d.y}`;}}function fetchTreeData(){d3.json('/mesh_tree_data').then(data =>{g.selectAll('*').remove();const root = d3.hierarchy(data,d => d.children);root.x0 = height / 2;root.y0 = 0;update(root,root);}).catch(error =>{console.error('Error fetching mesh data:',error);});}document.addEventListener('DOMContentLoaded',fetchTreeData);</script></body></html>"

/* END HTML MACROS AREA */

#endif // USE_HTML_FROM_MACROS
#endif // HTML_MACROS_H_
