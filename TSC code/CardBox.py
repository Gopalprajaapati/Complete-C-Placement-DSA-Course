def find_missing_or_volume(num_cards, card_data):  
      
    placed_positions = set()  
    min_x, min_y, min_z = float('inf'), float('inf'), float('inf')  
    max_x, max_y, max_z = float('-inf'), float('-inf'), float('-inf')  
      
    for card in card_data:  
        x, y, z, plane = card.split()  
        x, y, z = int(x), int(y), int(z)  
        placed_positions.add((x, y, z, plane))  
        min_x = min(min_x, x)  
        max_x = max(max_x, x)  
        min_y = min(min_y, y)  
        max_y = max(max_y, y)  
        min_z = min(min_z, z)  
        max_z = max(max_z, z)  
          
    expected_positions = set()  
      
    for x in range(min_x, max_x):  
        for y in range(min_y, max_y):  
            expected_positions.add((x, y, min_z, "xy"))  
            expected_positions.add((x, y, max_z, "xy"))  
      
    for x in range(min_x, max_x):  
        for z in range(min_z, max_z):  
            expected_positions.add((x, min_y, z, "xz"))  
            expected_positions.add((x, max_y, z, "xz"))  
      
    for y in range(min_y, max_y):  
        for z in range(min_z, max_z):  
            expected_positions.add((min_x, y, z, "yz"))  
            expected_positions.add((max_x, y, z, "yz"))  
      
    missing_card = None  
    for card in expected_positions:  
        if card not in placed_positions:  
            missing_card = card  
            break  
      
    if missing_card:  
        x, y, z, plane = missing_card  
        print(f"{x} {y} {z} {plane}", end="")  
    else:  
        volume = (max_x - min_x) * (max_y - min_y) * (max_z - min_z)  
        print(volume, end="")  
  
num_cards = int(input())  
card_data = [input().strip() for _ in range(num_cards)]  
find_missing_or_volume(num_cards, card_data)