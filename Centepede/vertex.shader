#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform vec2 screenResolution;
uniform vec2 spriteResolution;
uniform vec2 screenBorder;
uniform float tileSize;

void main()
{
    //normalize position vector																		// CoordinateSystem Map:
	vec3 normalizedPosition;																		//                                                         scrW = Width  of Screen in px
	//X																								//  Normalized:               Not normalized:              scrH = Height of Screen in px
    normalizedPosition.x = (position.x * tileSize + screenBorder.x) - screenResolution.x;			// -1,1-------------1,1       0,0----------scrW,0
																									//   |       |       |         |    |     |    |
	//Y																								//   |------0,0------|         |    |FIELD|    |
    normalizedPosition.y = (position.y * tileSize + screenBorder.y) * -1.0f + screenResolution.y;	//   |       |       |         |    |     |    |
	normalizedPosition.xy /= screenResolution.xy;													// -1,-1------------1,-1     0,scrH--------scrW,scrH
	//Z
	normalizedPosition.z = 0.0f;

    gl_Position = vec4(normalizedPosition, 1.0f);
	

	//normalize texCoord vector
    TexCoord.x = texCoord.x / spriteResolution.x;
	TexCoord.y = texCoord.y / spriteResolution.y;
}

